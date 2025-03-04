/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2011-2025 Asynchronous B.V.
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
#ifndef _BACKGROUND_EVENT_LOOP_H_
#define _BACKGROUND_EVENT_LOOP_H_

#include <boost/shared_ptr.hpp>
#include <string>
#include <pthread.h>

extern "C" {
	struct ev_loop;
	struct uv_loop_s;
}

namespace Passenger {
	using namespace std;
	using namespace boost;

	class SafeLibev;
	struct BackgroundEventLoopPrivate;

	/**
	 * Implements a libev event loop that runs in a background thread.
	 */
	struct BackgroundEventLoop {
		struct ev_loop *libev_loop;
		struct uv_loop_s *libuv_loop;
		boost::shared_ptr<SafeLibev> safe;
		BackgroundEventLoopPrivate *priv;

		BackgroundEventLoop(bool scalable = false, bool usesLibuv = true);
		~BackgroundEventLoop();

		void start(const string &threadName = "", unsigned int stackSize = 1024 * 1024);
		void stop();
		bool isStarted() const;
		pthread_t getNativeHandle() const;
	};

}

#endif /* _BACKGROUND_EVENT_LOOP_H_ */
