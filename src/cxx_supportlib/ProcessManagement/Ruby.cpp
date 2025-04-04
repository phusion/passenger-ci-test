/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2017-2025 Asynchronous B.V.
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

#include <string>
#include <vector>
#include <cstddef>
#include <cstdio>

#include <ProcessManagement/Spawn.h>
#include <ProcessManagement/Ruby.h>
#include <ResourceLocator.h>
#include <Exceptions.h>

namespace Passenger {

using namespace std;


void
runInternalRubyTool(const ResourceLocator &resourceLocator,
	const string &ruby, const vector<string> &args, int *status,
	SubprocessOutput *output, size_t maxOutputSize)
{
	string locationConfigFileEnv = "PASSENGER_LOCATION_CONFIGURATION_FILE="
		+ resourceLocator.getInstallSpec();
	string fullProgramPath;
	bool isRubyProgram;
	const char *command[
		4 // env, locationConfigEnvFile, ruby, fullProgramPath
		+ (args.size() - 1)
		+ 1 // NULL
	];
	unsigned int i = 0, j;

	if (args[0][0] == '/') {
		fullProgramPath = args[0];
	} else {
		fullProgramPath = resourceLocator.getBinDir() + "/" + args[0];
	}

	// The tool may be a wrapper script, e.g. one generated by Homebrew.
	// If it's a non-Ruby wrapper script then don't invoke it with Ruby.
	FILE *f = fopen(fullProgramPath.c_str(), "r");
	if (f == NULL) {
		throw RuntimeException("Unable to open " + fullProgramPath);
	}
	char line[1024];
	if (fgets(line, sizeof(line), f) == NULL) {
		if (ferror(f) != 0) {
			fclose(f);
			throw RuntimeException("Unable to read " + fullProgramPath);
		} else {
			throw RuntimeException(fullProgramPath + " is empty");
		}
	} else {
		isRubyProgram = strstr(line, "ruby") != NULL;
	}
	fclose(f);

	command[i++] = "env";
	command[i++] = locationConfigFileEnv.c_str();
	if (isRubyProgram) {
		command[i++] = ruby.c_str();
	}
	command[i++] = fullProgramPath.c_str();
	for (j = 1; j < args.size(); j++) {
		command[i++] = args[j].c_str();
	}
	command[i++] = NULL;

	SubprocessInfo info;
	if (output == NULL) {
		runCommand(command, info);
	} else {
		runCommandAndCaptureOutput(command, info, *output, maxOutputSize);
	}
	if (status != NULL) {
		*status = info.status;
	}
}


} // namespace Passenger
