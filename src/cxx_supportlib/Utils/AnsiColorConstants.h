/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2012-2025 Asynchronous B.V.
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
#ifndef _PASSENGER_ANSI_COLOR_CONSTANTS_H_

// '\033' == '\e' aka escape

#define ANSI_COLOR_RESET    "\033[0m"
#define ANSI_COLOR_BOLD     "\033[1m"
#define ANSI_COLOR_DGRAY    "\033[90m"
#define ANSI_COLOR_RED      "\033[31m"
#define ANSI_COLOR_GREEN    "\033[32m"
#define ANSI_COLOR_YELLOW   "\033[33m"
#define ANSI_COLOR_WHITE    "\033[37m"
#define ANSI_COLOR_BLACK_BG "\033[40m"
#define ANSI_COLOR_BLUE_BG  "\033[44m"

#endif /* _PASSENGER_ANSI_COLOR_CONSTANTS_H_ */
