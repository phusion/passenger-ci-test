/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2010-2025 Asynchronous B.V.
 *
 *  "Passenger", "Phusion Passenger" and "Union Station" are registered
 *  trademarks of Asynchronous B.V.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#ifndef _GNU_SOURCE
	// Needed for IOV_MAX on Linux:
	// https://bugzilla.redhat.com/show_bug.cgi?id=165427
	// Also needed for SO_PEERCRED.
	#define _GNU_SOURCE
#include <exception>
#endif

#include <oxt/system_calls.hpp>
#include <oxt/backtrace.hpp>
#include <oxt/macros.hpp>
#include <string>
#include <vector>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h> // IWYU pragma: keep; for __GLIBC__ macro
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <cmath>

#ifdef __linux__
	// For accept4 macros
	#include <sys/syscall.h>
	#include <linux/net.h>
#endif

#if defined(__APPLE__)
	#define HAVE_FPURGE
#elif defined(__GLIBC__)
	#include <stdio_ext.h>
	#define HAVE___FPURGE
#endif

#include <Exceptions.h>
#include <Constants.h>
#include <Utils/Timer.h>
#include <IOTools/IOUtils.h>
#include <StrIntTools/StrIntUtils.h>
#include <Utils/ScopeGuard.h>

namespace Passenger {

using namespace std;
using namespace oxt;

// Urgh, Solaris :-(
#ifndef AF_LOCAL
	#define AF_LOCAL AF_UNIX
#endif
#ifndef PF_LOCAL
	#define PF_LOCAL PF_UNIX
#endif

static WritevFunction writevFunction = syscalls::writev;


/****** Server address types support ******/

ServerAddressType
getSocketAddressType(const StaticString &address) {
	const char *data = address.c_str();
	size_t len = address.size();

	if (len > sizeof("unix:") - 1 && memcmp(data, "unix:", sizeof("unix:") - 1) == 0) {
		return SAT_UNIX;
	} else if (len > sizeof("tcp://") - 1 && memcmp(data, "tcp://", sizeof("tcp://") - 1) == 0) {
		return SAT_TCP;
	} else {
		return SAT_UNKNOWN;
	}
}

string
parseUnixSocketAddress(const StaticString &address) {
	if (getSocketAddressType(address) != SAT_UNIX) {
		throw ArgumentException("Not a valid Unix socket address");
	}
	return string(address.c_str() + sizeof("unix:") - 1, address.size() - sizeof("unix:") + 1);
}

void
parseTcpSocketAddress(const StaticString &address, string &host, unsigned short &port) {
	if (getSocketAddressType(address) != SAT_TCP) {
		throw ArgumentException("Not a valid TCP socket address");
	}

	StaticString hostAndPort(address.data() + sizeof("tcp://") - 1,
		address.size() - sizeof("tcp://") + 1);
	if (hostAndPort.empty()) {
		throw ArgumentException("Not a valid TCP socket address");
	}

	if (hostAndPort[0] == '[') {
		// IPv6 address, e.g.:
		// [::1]:3000
		const char *hostEnd = (const char *) memchr(hostAndPort.data(), ']',
			hostAndPort.size());
		if (hostEnd == NULL || hostAndPort.size() <= string::size_type(hostEnd - hostAndPort.data()) + 3) {
			throw ArgumentException("Not a valid TCP socket address");
		}

		const char *sep = hostEnd + 1;
		host.assign(hostAndPort.data() + 1, hostEnd - hostAndPort.data() - 1);
		port = stringToUint(StaticString(
			sep + 1,
			hostAndPort.data() + hostAndPort.size() - sep - 1
		));

	} else {
		// IPv4 address, e.g.:
		// 127.0.0.1:3000
		const char *sep = (const char *) memchr(hostAndPort.data(), ':', hostAndPort.size());
		if (sep == NULL || hostAndPort.size() <= string::size_type(sep - hostAndPort.data()) + 2) {
			throw ArgumentException("Not a valid TCP socket address");
		}

		host.assign(hostAndPort.data(), sep - hostAndPort.data());
		port = stringToUint(StaticString(
			sep + 1,
			hostAndPort.data() + hostAndPort.size() - sep - 1
		));
	}
}

bool
isLocalSocketAddress(const StaticString &address) {
	switch (getSocketAddressType(address)) {
	case SAT_UNIX:
		return true;
	case SAT_TCP: {
		string host;
		unsigned short port;

		parseTcpSocketAddress(address, host, port);
		return host == "127.0.0.1" || host == "::1" || host == "localhost";
	}
	default:
		throw ArgumentException("Unsupported socket address type");
	}
}


/****** Server socket creation ******/

int
createServer(const StaticString &address, unsigned int backlogSize, bool autoDelete,
	const char *file, unsigned int line)
{
	TRACE_POINT();
	switch (getSocketAddressType(address)) {
	case SAT_UNIX:
		return createUnixServer(parseUnixSocketAddress(address),
			backlogSize, autoDelete, file, line);
	case SAT_TCP: {
		string host;
		unsigned short port;

		parseTcpSocketAddress(address, host, port);
		return createTcpServer(host.c_str(), port, backlogSize, file, line);
	}
	default:
		throw ArgumentException(string("Unknown address type for '") + address + "'");
	}
}

int
createUnixServer(const StaticString &filename, unsigned int backlogSize, bool autoDelete,
	const char *file, unsigned int line)
{
	struct sockaddr_un addr;
	int fd, ret;

	if (filename.size() > sizeof(addr.sun_path) - 1) {
		string message = "Cannot create Unix socket '";
		message.append(filename.toString());
		message.append("': filename is too long.");
		throw RuntimeException(message);
	}

	fd = syscalls::socket(PF_LOCAL, SOCK_STREAM, 0);
	if (fd == -1) {
		int e = errno;
		throw SystemException("Cannot create a Unix socket file descriptor", e);
	}

	FdGuard guard(fd, file, line);
	addr.sun_family = AF_LOCAL;
	strncpy(addr.sun_path, filename.c_str(), filename.size());
	addr.sun_path[filename.size()] = '\0';

	if (autoDelete) {
		do {
			ret = unlink(filename.c_str());
		} while (ret == -1 && errno == EINTR);
	}

	ret = syscalls::bind(fd, (const struct sockaddr *) &addr, sizeof(addr));
	if (ret == -1) {
		int e = errno;
		string message = "Cannot bind Unix socket '";
		message.append(filename.toString());
		message.append("'");
		throw SystemException(message, e);
	}

	if (backlogSize == 0) {
		backlogSize = 1024;
	}
	ret = syscalls::listen(fd, backlogSize);
	if (ret == -1) {
		int e = errno;
		string message = "Cannot listen on Unix socket '";
		message.append(filename.toString());
		message.append("'");
		safelyClose(fd, true);
		throw SystemException(message, e);
	}

	guard.clear();
	return fd;
}

int
createTcpServer(const char *address, unsigned short port, unsigned int backlogSize,
	const char *file, unsigned int line)
{
	union {
		struct sockaddr_in v4;
		struct sockaddr_in6 v6;
	} addr;
	sa_family_t family;
	int fd, ret, optval;

	memset(&addr, 0, sizeof(addr));
	family = addr.v4.sin_family = AF_INET;
	ret = inet_pton(AF_INET, address, &addr.v4.sin_addr.s_addr);
	if (ret == 0) {
		// Might be an IPv6 address.
		memset(&addr, 0, sizeof(addr));
		family = addr.v6.sin6_family = AF_INET6;
		ret = inet_pton(AF_INET6, address, &addr.v6.sin6_addr.s6_addr);
	}
	if (ret < 0) {
		int e = errno;
		string message = "Cannot parse the IP address '";
		message.append(address);
		message.append("'");
		throw SystemException(message, e);
	} else if (ret == 0) {
		string message = "Cannot parse the IP address '";
		message.append(address);
		message.append("'");
		throw ArgumentException(message);
	}

	if (family == AF_INET) {
		addr.v4.sin_port = htons(port);
		fd = syscalls::socket(PF_INET, SOCK_STREAM, 0);
	} else {
		addr.v6.sin6_port = htons(port);
		fd = syscalls::socket(PF_INET6, SOCK_STREAM, 0);
	}
	if (fd == -1) {
		int e = errno;
		throw SystemException("Cannot create a TCP socket file descriptor", e);
	}

	optval = 1;
	if (syscalls::setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
		&optval, sizeof(optval)) == -1)
	{
		int e = errno;
		fprintf(stderr, "so_reuseaddr failed: %s\n", strerror(e));
	}
	// Ignore SO_REUSEADDR error, it's not fatal.

	FdGuard guard(fd, file, line);
	if (family == AF_INET) {
		ret = syscalls::bind(fd, (const struct sockaddr *) &addr.v4, sizeof(struct sockaddr_in));
	} else {
		ret = syscalls::bind(fd, (const struct sockaddr *) &addr.v6, sizeof(struct sockaddr_in6));
	}
	if (ret == -1) {
		int e = errno;
		string message = "Cannot bind a TCP socket on address '";
		message.append(address);
		message.append("' port ");
		message.append(toString(port));
		throw SystemException(message, e);
	}

	if (backlogSize == 0) {
		backlogSize = DEFAULT_SOCKET_BACKLOG;
	}
	ret = syscalls::listen(fd, backlogSize);
	if (ret == -1) {
		int e = errno;
		string message = "Cannot listen on TCP socket '";
		message.append(address);
		message.append("' port ");
		message.append(toString(port));
		throw SystemException(message, e);
	}

	guard.clear();
	return fd;
}


/****** Socket connection establishment (blocking) ******/

int
connectToServer(const StaticString &address, const char *file, unsigned int line) {
	TRACE_POINT();
	switch (getSocketAddressType(address)) {
	case SAT_UNIX:
		return connectToUnixServer(parseUnixSocketAddress(address), file, line);
	case SAT_TCP: {
		string host;
		unsigned short port;

		parseTcpSocketAddress(address, host, port);
		return connectToTcpServer(host, port, file, line);
	}
	default:
		throw ArgumentException(string("Unknown address type for '") + address + "'");
	}
}

int
connectToUnixServer(const StaticString &filename, const char *file,
	unsigned int line)
{
	int fd = syscalls::socket(PF_UNIX, SOCK_STREAM, 0);
	if (fd == -1) {
		int e = errno;
		throw SystemException("Cannot create a Unix socket file descriptor", e);
	}

	FdGuard guard(fd, file, line);
	int ret;
	struct sockaddr_un addr;

	if (filename.size() > sizeof(addr.sun_path) - 1) {
		string message = "Cannot connect to Unix socket '";
		message.append(filename.data(), filename.size());
		message.append("': filename is too long.");
		throw RuntimeException(message);
	}

	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path, filename.c_str(), filename.size());
	addr.sun_path[filename.size()] = '\0';

	bool retry = true;
	int counter = 0;
	while (retry) {
		ret = syscalls::connect(fd, (const sockaddr *) &addr, sizeof(addr));
		if (ret == -1) {
			#if defined(sun) || defined(__sun)
				/* Solaris has this nice kernel bug where connecting to
				 * a newly created Unix socket which is obviously
				 * connectable can cause an ECONNREFUSED. So we retry
				 * in a loop.
				 */
				retry = errno == ECONNREFUSED;
			#else
				retry = false;
			#endif
			retry = retry && counter < 9;

			if (retry) {
				syscalls::usleep((useconds_t) (10000 * pow((double) 2, (double) counter)));
				counter++;
			} else {
				int e = errno;
				string message("Cannot connect to Unix socket '");
				message.append(filename.toString());
				message.append("'");
				throw SystemException(message, e);
			}
		} else {
			guard.clear();
			return fd;
		}
	}
	abort();   // Never reached.
}

int
connectToTcpServer(const StaticString &hostname, unsigned int port,
	const char *file, unsigned int line)
{
	struct addrinfo hints, *res;
	int ret, e, fd;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family   = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	ret = getaddrinfo(hostname.c_str(), toString(port).c_str(), &hints, &res);
	if (ret != 0) {
		string message = "Cannot resolve IP address '";
		message.append(hostname.toString());
		message.append(":");
		message.append(toString(port));
		message.append("': ");
		message.append(gai_strerror(ret));
		throw IOException(message);
	}

	try {
		fd = syscalls::socket(PF_INET, SOCK_STREAM, 0);
	} catch (...) {
		freeaddrinfo(res);
		throw;
	}
	if (fd == -1) {
		e = errno;
		freeaddrinfo(res);
		throw SystemException("Cannot create a TCP socket file descriptor", e);
	}

	try {
		ret = syscalls::connect(fd, res->ai_addr, res->ai_addrlen);
	} catch (...) {
		freeaddrinfo(res);
		safelyClose(fd, true);
		throw;
	}
	e = errno;
	freeaddrinfo(res);
	if (ret == -1) {
		string message = "Cannot connect to TCP socket '";
		message.append(hostname.toString());
		message.append(":");
		message.append(toString(port));
		message.append("'");
		safelyClose(fd, true);
		throw SystemException(message, e);
	}

	P_LOG_FILE_DESCRIPTOR_OPEN3(fd, file, line);

	return fd;
}


/****** Socket connection establishment (non-blocking) ******/

std::pair<int, bool>
createNonBlockingSocketConnection(const StaticString &address, const char *file, unsigned int line) {
	TRACE_POINT();
	switch (getSocketAddressType(address)) {
	case SAT_UNIX:
		return createNonBlockingUnixSocketConnection(parseUnixSocketAddress(address), file, line);
	case SAT_TCP: {
		string host;
		unsigned short port;

		parseTcpSocketAddress(address, host, port);
		return createNonBlockingTcpSocketConnection(host, port, file, line);
	}
	default:
		throw ArgumentException(string("Unknown address type for '") + address + "'");
	}
}

std::pair<int, bool>
createNonBlockingUnixSocketConnection(const StaticString &filename, const char *file, unsigned int line) {
	struct sockaddr_un addr;

	if (filename.size() > sizeof(addr.sun_path) - 1) {
		string message = "Cannot connect to Unix socket '";
		message.append(filename.data(), filename.size());
		message.append("': filename is too long.");
		throw ArgumentException(message);
	}


	int fd = syscalls::socket(PF_UNIX, SOCK_STREAM, 0);
	if (fd == -1) {
		int e = errno;
		throw SystemException("Cannot create a Unix socket file descriptor", e);
	}

	int ret;
	FdGuard guard(fd, nullptr, 0);
	P_LOG_FILE_DESCRIPTOR_OPEN4(fd, file, line, "NonBlockingUnixSocketConnection");
	setNonBlocking(fd);

	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path, filename.data(), filename.size());
	addr.sun_path[filename.size()] = '\0';

	ret = syscalls::connect(fd, (const sockaddr *) &addr, sizeof(addr));
	if (ret == -1) {
		if (errno == EINPROGRESS || errno == EWOULDBLOCK) {
			guard.clear();
			return std::make_pair(fd, false);
		} else if (errno == EISCONN) {
			guard.clear();
			return std::make_pair(fd, true);
		} else {
			int e = errno;
			string message = "Cannot connect to Unix socket '";
			message.append(filename.data(), filename.size());
			message.append("'");
			throw SystemException(message, e);
		}
	} else {
		guard.clear();
		return std::make_pair(fd, true);
	}
}

std::pair<int, bool>
createNonBlockingTcpSocketConnection(const StaticString &hostname, unsigned int port, const char *file, unsigned int line) {
	const string hostnameCopy = string(hostname.data(), hostname.size());
	const string portString = toString(port);
	struct addrinfo hints, *res;
	int ret;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family   = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	ret = getaddrinfo(hostnameCopy.c_str(), portString.c_str(),
		&hints, &res);
	if (ret != 0) {
		string message = "Cannot resolve IP address '";
		message.append(hostname.data(), hostname.size());
		message.append(":");
		message.append(portString);
		message.append("': ");
		message.append(gai_strerror(ret));
		throw IOException(message);
	}


	int fd = syscalls::socket(PF_INET, SOCK_STREAM, 0);
	if (fd == -1) {
		int e = errno;
		throw SystemException("Cannot create a TCP socket file descriptor", e);
	}

	FdGuard guard(fd, nullptr, 0);
	P_LOG_FILE_DESCRIPTOR_OPEN4(fd, file, line, "NonBlockingTcpSocketConnection");
	setNonBlocking(fd);


	ret = syscalls::connect(fd, res->ai_addr, res->ai_addrlen);
	if (ret == -1) {
		if (errno == EINPROGRESS || errno == EWOULDBLOCK) {
			guard.clear();
			return make_pair(fd, false);
		} else if (errno == EISCONN) {
			freeaddrinfo(res);
			guard.clear();
			return make_pair(fd, true);
		} else {
			int e = errno;
			string message = "Cannot connect to TCP socket '";
			message.append(hostname);
			message.append(":");
			message.append(portString);
			message.append("'");
			throw SystemException(message, e);
		}
	} else {
		freeaddrinfo(res);
		guard.clear();
		return make_pair(fd, true);
	}
}


/****** Scope guards ******/

FdGuard::FdGuard(FdGuard &&other)
	: mFd(other.mFd)
{
	other.mFd = -1;
}

FdGuard::FdGuard(int fd, const char *sourceFile, unsigned int sourceLine)
	: mFd(fd)
{
	if (mFd != -1 && sourceFile != nullptr) {
		P_LOG_FILE_DESCRIPTOR_OPEN3(fd, sourceFile, sourceLine);
	}
}

FdGuard::~FdGuard() noexcept(false) {
	if (mFd != -1) {
		try {
			safelyClose(mFd);
		} catch (const std::exception &e) {
			bool uncaughtException =
				#if __cplusplus >= 201703L
					std::uncaught_exceptions() > 0;
				#else
					std::uncaught_exception();
				#endif
			if (uncaughtException) {
				P_WARN("Error closing file descriptor " << mFd << ": " << e.what());
				return;
			} else {
				throw e;
			}
		}
		P_LOG_FILE_DESCRIPTOR_CLOSE(mFd);
	}
}

FdGuard &
FdGuard::operator=(FdGuard &&other) {
	if (this != &other) {
		if (mFd != -1) {
			safelyClose(mFd);
			P_LOG_FILE_DESCRIPTOR_CLOSE(mFd);
		}
		mFd = other.mFd;
		other.mFd = -1;
	}
	return *this;
}

void
FdGuard::clear() noexcept {
	mFd = -1;
}

void
FdGuard::runNow() noexcept(false) {
	if (mFd != -1) {
		safelyClose(mFd);
		P_LOG_FILE_DESCRIPTOR_CLOSE(mFd);
		mFd = -1;
	}
}


/****** Other ******/

bool
purgeStdio(FILE *f) {
	#if defined(HAVE_FPURGE)
		fpurge(f);
		return true;
	#elif defined(HAVE___FPURGE)
		__fpurge(f);
		return true;
	#else
		return false;
	#endif
}

void
setBlocking(int fd) {
	int flags, ret;

	do {
		flags = fcntl(fd, F_GETFL);
	} while (flags == -1 && errno == EINTR);
	if (flags == -1) {
		int e = errno;
		throw SystemException("Cannot set socket to blocking mode: "
			"cannot get socket flags",
			e);
	}
	do {
		ret = fcntl(fd, F_SETFL, flags & ~O_NONBLOCK);
	} while (ret == -1 && errno == EINTR);
	if (ret == -1) {
		int e = errno;
		throw SystemException("Cannot set socket to blocking mode: "
			"cannot set socket flags",
			e);
	}
}

void
setNonBlocking(int fd) {
	int flags, ret;

	do {
		flags = fcntl(fd, F_GETFL);
	} while (flags == -1 && errno == EINTR);
	if (flags == -1) {
		int e = errno;
		throw SystemException("Cannot set socket to non-blocking mode: "
			"cannot get socket flags",
			e);
	}
	do {
		ret = fcntl(fd, F_SETFL, flags | O_NONBLOCK);
	} while (ret == -1 && errno == EINTR);
	if (ret == -1) {
		int e = errno;
		throw SystemException("Cannot set socket to non-blocking mode: "
			"cannot set socket flags",
			e);
	}
}

int
callAccept4(int sock, struct sockaddr *addr, socklen_t *addr_len, int options) {
	#if defined(HAVE_ACCEPT4)
		int ret;
		do {
			ret = ::accept4(sock, addr, addr_len, options);
		} while (ret == -1 && errno == EINTR);
		return ret;
	#else
		errno = ENOSYS;
		return -1;
	#endif
}

bool
pingTcpServer(const StaticString &host, unsigned int port, unsigned long long *timeout) {
	TRACE_POINT();
	std::pair<int, bool> nbcResult;

	try {
		nbcResult = createNonBlockingTcpSocketConnection(host, port, __FILE__, __LINE__);
	} catch (const SystemException &e) {
		if (e.code() == ECONNREFUSED) {
			return false;
		} else {
			throw e;
		}
	}
	FdGuard guard(nbcResult.first, nullptr, 0);
	if (nbcResult.second) {
		return true;
	}

	// Cannot connect to the port yet, but that may not mean the
	// port is unavailable. So poll the socket.

	bool connectable;
	try {
		connectable = waitUntilWritable(nbcResult.first, timeout);
	} catch (const SystemException &e) {
		throw SystemException("Error polling TCP socket "
			+ host + ":" + toString(port), e.code());
	}
	if (!connectable) {
		// Timed out. Assume port is not available.
		return false;
	}

	// Now check the final connection establishment status.

	int connectError = 0;
	socklen_t connectErrorLen = sizeof(connectError);
	if (getsockopt(nbcResult.first, SOL_SOCKET, SO_ERROR, &connectError, &connectErrorLen) == -1) {
		throw SystemException("Error checking TCP socket " + host + ":" + toString(port)
			+ " connection establishment status", connectError);
	}
	if (connectError == 0) {
		return true;
	} else if (connectError == ECONNREFUSED) {
		return false;
	} else {
		throw SystemException("Error connecting to TCP socket " + host + ":"
			+ toString(port), connectError);
	}
}

SocketPair
createUnixSocketPair(const char *file, unsigned int line) {
	int fds[2];
	FileDescriptor sockets[2];

	if (syscalls::socketpair(AF_UNIX, SOCK_STREAM, 0, fds) == -1) {
		int e = errno;
		throw SystemException("Cannot create a Unix socket pair", e);
	} else {
		sockets[0].assign(fds[0], file, line);
		sockets[1].assign(fds[1], file, line);
		return SocketPair(sockets[0], sockets[1]);
	}
}

Pipe
createPipe(const char *file, unsigned int line) {
	int fds[2];
	FileDescriptor p[2];

	if (syscalls::pipe(fds) == -1) {
		int e = errno;
		throw SystemException("Cannot create a pipe", e);
	} else {
		p[0].assign(fds[0], file, line);
		p[1].assign(fds[1], file, line);
		return Pipe(p[0], p[1]);
	}
}

static bool
waitUntilIOEvent(int fd, short event, unsigned long long *timeout) {
	struct pollfd pfd;
	int ret;

	pfd.fd = fd;
	pfd.events = event;
	pfd.revents = 0;

	Timer<> timer;
	ret = syscalls::poll(&pfd, 1, *timeout / 1000);
	if (ret == -1) {
		int e = errno;
		throw SystemException("poll() failed", e);
	} else {
		unsigned long long elapsed = timer.usecElapsed();
		if (elapsed > *timeout) {
			*timeout = 0;
		} else {
			*timeout -= elapsed;
		}
		return ret != 0;
	}
}

bool
waitUntilReadable(int fd, unsigned long long *timeout) {
	return waitUntilIOEvent(fd, POLLIN, timeout);
}

bool
waitUntilWritable(int fd, unsigned long long *timeout) {
	return waitUntilIOEvent(fd, POLLOUT | POLLHUP, timeout);
}

unsigned int
readExact(int fd, void *buf, unsigned int size, unsigned long long *timeout) {
	ssize_t ret;
	unsigned int alreadyRead = 0;

	while (alreadyRead < size) {
		if (timeout != NULL && !waitUntilReadable(fd, timeout)) {
			throw TimeoutException("Cannot read enough data within the specified timeout");
		}
		ret = syscalls::read(fd, (char *) buf + alreadyRead, size - alreadyRead);
		if (ret == -1) {
			int e = errno;
			throw SystemException("read() failed", e);
		} else if (ret == 0) {
			return alreadyRead;
		} else {
			alreadyRead += ret;
		}
	}
	return alreadyRead;
}

void
writeExact(int fd, const void *data, unsigned int size, unsigned long long *timeout) {
	ssize_t ret;
	unsigned int written = 0;
	while (written < size) {
		if (timeout != NULL && !waitUntilWritable(fd, timeout)) {
			throw TimeoutException("Cannot write enough data within the specified timeout");
		}
		ret = syscalls::write(fd, (const char *) data + written, size - written);
		if (ret == -1) {
			int e = errno;
			throw SystemException("write() failed", e);
		} else {
			written += ret;
		}
	}
}

void
writeExact(int fd, const StaticString &data, unsigned long long *timeout) {
	const char * restrict data_ptr = data.data();
	writeExact(fd, data_ptr, data.size(), timeout);
}

/**
 * Converts an array of StaticStrings to a corresponding array of iovec structures,
 * returning the size sum in bytes of all StaticStrings.
 */
static size_t
staticStringArrayToIoVec(const StaticString ary[], size_t count, struct iovec *vec, size_t &vecCount) {
	size_t total = 0;
	size_t i;
	for (i = 0, vecCount = 0; i < count; i++) {
		/* No idea whether all writev() implementations support iov_len == 0,
		 * but I'd rather not risk finding out.
		 */
		if (ary[i].size() > 0) {
			/* I know writev() doesn't write to iov_base, but on some
			 * platforms it's still defined as non-const char *
			 * :-(
			 */
			vec[vecCount].iov_base = const_cast<char *>(ary[i].data());
			vec[vecCount].iov_len  = ary[i].size();
			total += ary[i].size();
			vecCount++;
		}
	}
	return total;
}

/**
 * Suppose that the given IO vectors are placed adjacent to each other
 * in a single contiguous block of memory. Given a position inside this
 * block of memory, this function will calculate the index in the IO vector
 * array and the offset inside that IO vector that corresponds with
 * the position.
 *
 * For example, given the following array of IO vectors:
 * { "AAA", "BBBB", "CC" }
 * Position 0 would correspond to the first item, offset 0.
 * Position 1 would correspond to the first item, offset 1.
 * Position 5 would correspond to the second item, offset 2.
 * And so forth.
 *
 * If the position is outside the bounds of the array, then index will be
 * set to count + 1 and offset to 0.
 */
static void
findDataPositionIndexAndOffset(struct iovec data[], size_t count,
	size_t position, size_t * restrict index, size_t * restrict offset)
{
	size_t i;
	size_t begin = 0;

	for (i = 0; i < count; i++) {
		size_t end = begin + data[i].iov_len;
		if (OXT_LIKELY(begin <= position)) {
			if (position < end) {
				*index = i;
				*offset = position - begin;
				return;
			} else {
				begin = end;
			}
		} else {
			// Never reached.
			abort();
		}
	}
	*index = count;
	*offset = 0;
}

static ssize_t
realGatheredWrite(int fd, const StaticString *data, unsigned int dataCount, string &restBuffer,
	struct iovec *iov)
{
	size_t totalSize, iovCount, i;
	ssize_t ret;

	if (restBuffer.empty()) {
		totalSize = staticStringArrayToIoVec(data, dataCount, iov, iovCount);
		if (totalSize == 0) {
			errno = 0;
			return 0;
		}

		ret = writevFunction(fd, iov, std::min(iovCount, (size_t) IOV_MAX));
		if (ret == -1) {
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				// Nothing could be written without blocking, so put
				// everything in the rest buffer.
				int e = errno;
				restBuffer.reserve(totalSize);
				for (i = 0; i < iovCount; i++) {
					restBuffer.append((const char *) iov[i].iov_base,
						iov[i].iov_len);
				}
				errno = e;
				return 0;
			} else {
				return -1;
			}
		} else if ((size_t) ret < totalSize) {
			size_t index, offset;

			// Put all unsent data in the rest buffer.
			restBuffer.reserve(ret);
			findDataPositionIndexAndOffset(iov, iovCount, ret, &index, &offset);
			for (i = index; i < iovCount; i++) {
				if (i == index) {
					restBuffer.append(
						((const char *) iov[i].iov_base) + offset,
						iov[i].iov_len - offset);
				} else {
					restBuffer.append(
						(const char *) iov[i].iov_base,
						iov[i].iov_len);
				}
			}

			// TODO: we should call writev() again if iovCount > iovMax
			// in order to send out the rest of the data without
			// putting them in the rest buffer.

			return ret;
		} else {
			// Everything is sent, and the rest buffer was empty anyway, so
			// just return.
			return totalSize;
		}
	} else {
		iov[0].iov_base = const_cast<char *>(restBuffer.data());
		iov[0].iov_len  = restBuffer.size();
		totalSize = staticStringArrayToIoVec(data, dataCount, iov + 1, iovCount);
		totalSize += restBuffer.size();
		iovCount++;

		ret = writevFunction(fd, iov, std::min(iovCount, (size_t) IOV_MAX));
		if (ret == -1) {
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				// Nothing could be written without blocking, so
				// append all data into the rest buffer.
				int e = errno;
				restBuffer.reserve(totalSize);
				for (i = 1; i < iovCount; i++) {
					restBuffer.append(
						(const char *) iov[i].iov_base,
						iov[i].iov_len);
				}
				errno = e;
				return 0;
			} else {
				return -1;
			}
		} else {
			string::size_type restBufferSize = restBuffer.size();
			size_t restBufferSent = std::min((size_t) ret, (size_t) restBufferSize);

			// Remove everything in the rest buffer that we've been able to send.
			restBuffer.erase(0, restBufferSent);
			if (restBuffer.empty()) {
				size_t index, offset;

				// Looks like everything in the rest buffer was sent.
				// Put all unsent data into the rest buffer.
				findDataPositionIndexAndOffset(iov, iovCount, ret,
					&index, &offset);
				for (i = index; i < iovCount; i++) {
					if (i == index) {
						restBuffer.append(
							((const char *) iov[i].iov_base) + offset,
							iov[i].iov_len - offset);
					} else {
						restBuffer.append(
							(const char *) iov[i].iov_base,
							iov[i].iov_len);
					}
				}

				// TODO: we should call writev() again if
				// iovCount > iovMax && ret < totalSize
				// in order to send out the rest of the data without
				// putting them in the rest buffer.
			} else {
				// The rest buffer could only be partially sent out, so
				// nothing in 'data' could be sent. Append everything
				// in 'data' into the rest buffer.
				restBuffer.reserve(totalSize - ret);
				for (i = 1; i < iovCount; i++) {
					restBuffer.append(
						(const char *) iov[i].iov_base,
						iov[i].iov_len);
				}
			}
			return ret;
		}
	}
}

ssize_t
gatheredWrite(int fd, const StaticString *data, unsigned int dataCount, string &restBuffer) {
	if (dataCount < 8) {
		struct iovec iov[8];
		return realGatheredWrite(fd, data, dataCount, restBuffer, iov);
	} else {
		vector<struct iovec> iov;
		iov.reserve(dataCount + 1);
		return realGatheredWrite(fd, data, dataCount, restBuffer, &iov[0]);
	}
}

static size_t
eraseBeginningOfIoVec(struct iovec *iov, size_t count, size_t index, size_t offset) {
	size_t i, newCount;
	for (i = index, newCount = 0; i < count; i++, newCount++) {
		if (newCount == 0) {
			iov[newCount].iov_base = (char *) iov[i].iov_base + offset;
			iov[newCount].iov_len  = iov[i].iov_len - offset;
		} else {
			iov[newCount].iov_base = iov[i].iov_base;
			iov[newCount].iov_len  = iov[i].iov_len;
		}
	}
	return newCount;
}

static void
realGatheredWrite(int fd, const StaticString *data, unsigned int count, unsigned long long *timeout,
	struct iovec *iov)
{
	size_t total, iovCount;
	size_t written = 0;

	total = staticStringArrayToIoVec(data, count, iov, iovCount);

	while (written < total) {
		if (timeout != NULL && !waitUntilWritable(fd, timeout)) {
			throw TimeoutException("Cannot write enough data within the specified timeout");
		}
		ssize_t ret = writevFunction(fd, iov, std::min(iovCount, (size_t) IOV_MAX));
		if (ret == -1) {
			int e = errno;
			throw SystemException("Unable to write all data", e);
		} else {
			size_t index, offset;

			written += ret;
			findDataPositionIndexAndOffset(iov, iovCount, ret, &index, &offset);
			iovCount = eraseBeginningOfIoVec(iov, iovCount, index, offset);
		}
	}
	assert(written == total);
}

void
gatheredWrite(int fd, const StaticString *data, unsigned int count, unsigned long long *timeout) {
	if (count <= 8) {
		struct iovec iov[8];
		realGatheredWrite(fd, data, count, timeout, iov);
	} else {
		vector<struct iovec> iov;
		iov.reserve(count);
		realGatheredWrite(fd, data, count, timeout, &iov[0]);
	}
}

void
setWritevFunction(WritevFunction func) {
	if (func != NULL) {
		writevFunction = func;
	} else {
		writevFunction = syscalls::writev;
	}
}

int
readFileDescriptor(int fd, unsigned long long *timeout) {
	if (timeout != NULL && !waitUntilReadable(fd, timeout)) {
		throw TimeoutException("Cannot receive file descriptor within the specified timeout");
	}

	struct msghdr msg;
	struct iovec vec;
	char dummy[1];
	#if defined(__APPLE__) || defined(__SOLARIS__)
		// File descriptor passing macros (CMSG_*) seem to be broken
		// on 64-bit MacOS X. This structure works around the problem.
		struct {
			struct cmsghdr header;
			int fd;
		} control_data;
		#define EXPECTED_CMSG_LEN sizeof(control_data)
	#else
		char control_data[CMSG_SPACE(sizeof(int))];
		#define EXPECTED_CMSG_LEN CMSG_LEN(sizeof(int))
	#endif
	struct cmsghdr *control_header;
	int ret;

	msg.msg_name    = NULL;
	msg.msg_namelen = 0;

	dummy[0]       = '\0';
	vec.iov_base   = dummy;
	vec.iov_len    = sizeof(dummy);
	msg.msg_iov    = &vec;
	msg.msg_iovlen = 1;

	msg.msg_control    = (caddr_t) &control_data;
	msg.msg_controllen = sizeof(control_data);
	msg.msg_flags      = 0;

	ret = syscalls::recvmsg(fd, &msg, 0);
	if (ret == -1) {
		int err = errno;
		throw SystemException("Cannot read file descriptor with recvmsg()", err);
	}

	control_header = CMSG_FIRSTHDR(&msg);
	if (control_header == NULL) {
		throw IOException("No valid file descriptor received.");
	}
	if (control_header->cmsg_len   != EXPECTED_CMSG_LEN
	 || control_header->cmsg_level != SOL_SOCKET
	 || control_header->cmsg_type  != SCM_RIGHTS) {
		throw IOException("No valid file descriptor received.");
	}

	#if defined(__APPLE__) || defined(__SOLARIS__)
		return control_data.fd;
	#else
		return *((int *) CMSG_DATA(control_header));
	#endif
}

void
writeFileDescriptor(int fd, int fdToSend, unsigned long long *timeout) {
	if (timeout != NULL && !waitUntilWritable(fd, timeout)) {
		throw TimeoutException("Cannot send file descriptor within the specified timeout");
	}

	struct msghdr msg;
	struct iovec vec;
	char dummy[1];
	#if defined(__APPLE__) || defined(__SOLARIS__)
		struct {
			struct cmsghdr header;
			int fd;
		} control_data;
	#else
		char control_data[CMSG_SPACE(sizeof(int))];
	#endif
	struct cmsghdr *control_header;
	int ret;

	memset(&msg, 0, sizeof(msg));
	memset(&control_data, 0, sizeof(control_data));

	msg.msg_name = NULL;
	msg.msg_namelen = 0;

	/* Linux and Solaris require msg_iov to be non-NULL. */
	dummy[0]       = '\0';
	vec.iov_base   = dummy;
	vec.iov_len    = sizeof(dummy);
	msg.msg_iov    = &vec;
	msg.msg_iovlen = 1;

	msg.msg_control    = (caddr_t) &control_data;
	msg.msg_controllen = sizeof(control_data);
	msg.msg_flags      = 0;

	control_header = CMSG_FIRSTHDR(&msg);
	control_header->cmsg_level = SOL_SOCKET;
	control_header->cmsg_type  = SCM_RIGHTS;
	#if defined(__APPLE__) || defined(__SOLARIS__)
		control_header->cmsg_len = sizeof(control_data);
		control_data.fd = fdToSend;
	#else
		control_header->cmsg_len = CMSG_LEN(sizeof(int));
		memcpy(CMSG_DATA(control_header), &fdToSend, sizeof(int));
	#endif

	ret = syscalls::sendmsg(fd, &msg, 0);
	if (ret == -1) {
		int err = errno;
		throw SystemException("Cannot send file descriptor with sendmsg()", err);
	}
}

void
readPeerCredentials(int sock, uid_t *uid, gid_t *gid) {
	union {
		struct sockaddr genericAddress;
		struct sockaddr_un unixAddress;
		struct sockaddr_in inetAddress;
		struct sockaddr_in6 inetAddress6;
	} addr;
	socklen_t len = sizeof(addr);
	int ret;

	/*
	 * The functions for receiving the peer credentials are not guaranteed to
	 * fail if the socket is not a Unix domain socket. For example, OS X getpeereid()
	 * just returns garbage when invoked on a TCP socket. So we check here
	 * whether 'sock' is a Unix domain socket.
	 */
	do {
		ret = getsockname(sock, &addr.genericAddress, &len);
	} while (ret == -1 && errno == EINTR);
	if (ret == -1) {
		int e = errno;
		throw SystemException("Unable to autodetect socket type (getsockname() failed)", e);
	}
	if (addr.genericAddress.sa_family != AF_LOCAL) {
		throw SystemException("Cannot receive process credentials: the connection is not a Unix domain socket",
			EPROTONOSUPPORT);
	}

	#if defined(__linux__)
		struct ucred credentials;
		socklen_t ucred_length = sizeof(struct ucred);

		if (getsockopt(sock, SOL_SOCKET, SO_PEERCRED, &credentials, &ucred_length) != 0) {
			int e = errno;
			throw SystemException("Cannot receive process credentials over Unix domain socket", e);
		}

		*uid = credentials.uid;
		*gid = credentials.gid;
	#elif defined(__FreeBSD__) || defined(__APPLE__)
		if (getpeereid(sock, uid, gid) == -1) {
			int e = errno;
			throw SystemException("Cannot receive process credentials over Unix domain socket", e);
		}
	#else
		throw SystemException("Cannot receive process credentials over Unix domain socket", ENOSYS);
	#endif
}

void
safelyClose(int fd, bool ignoreErrors) {
	if (syscalls::close(fd) == -1) {
		/* FreeBSD has a kernel bug which can cause close() to return ENOTCONN.
		 * This is harmless, ignore it. We check for this problem on all
		 * platforms because some OSes might borrow Unix domain socket
		 * code from FreeBSD.
		 * http://www.freebsd.org/cgi/query-pr.cgi?pr=79138
		 * http://www.freebsd.org/cgi/query-pr.cgi?pr=144061
		 */
		if (errno != ENOTCONN && !ignoreErrors) {
			int e = errno;
			throw SystemException("Cannot close file descriptor", e);
		}
	}
}

pair<string, bool>
readAll(int fd, size_t maxSize) {
	string result;
	char buf[1024 * 32];
	ssize_t ret;
	bool eofReached = false;

	while (result.size() < maxSize) {
		do {
			ret = read(fd, buf, std::min<size_t>(sizeof(buf),
				maxSize - result.size()));
		} while (ret == -1 && errno == EINTR);
		if (ret == 0) {
			eofReached = true;
			break;
		} else if (ret == -1) {
			if (errno == ECONNRESET) {
				eofReached = true;
				break;
			} else {
				int e = errno;
				throw SystemException("Cannot read from file descriptor", e);
			}
		} else {
			result.append(buf, ret);
		}
	}

	return make_pair(result, eofReached);
}


} // namespace Passenger
