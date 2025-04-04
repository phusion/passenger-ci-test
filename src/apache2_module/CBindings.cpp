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

#include "Hooks.h"
#include "Config.h"
#include <httpd.h>
#include <http_config.h>


using namespace Passenger;


extern "C" void *
passenger_create_dir_config(apr_pool_t *p, char *dirspec) {
	return Apache2Module::createDirConfig(p, dirspec);
}

extern "C" void *
passenger_merge_dir_config(apr_pool_t *p, void *basev, void *addv) {
	return Apache2Module::mergeDirConfig(p, basev, addv);
}

extern "C" void
passenger_register_hooks(apr_pool_t *p) {
	Apache2Module::registerHooks(p);
}
