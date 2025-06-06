/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2018-2025 Asynchronous B.V.
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
#ifndef _PASSENGER_WRAPPER_REGISTRY_CBINDINGS_H_
#define _PASSENGER_WRAPPER_REGISTRY_CBINDINGS_H_

#include <stddef.h>

#ifdef __cplusplus
	extern "C" {
#endif


typedef void PsgWrapperRegistryEntry;

int psg_wrapper_registry_entry_is_null(const PsgWrapperRegistryEntry *entry);
const char *psg_wrapper_registry_entry_get_language(const PsgWrapperRegistryEntry *entry, size_t *len);


typedef void PsgWrapperRegistry;

PsgWrapperRegistry *psg_wrapper_registry_new();
void psg_wrapper_registry_free(PsgWrapperRegistry *registry);

void psg_wrapper_registry_finalize(PsgWrapperRegistry *registry);
const PsgWrapperRegistryEntry *psg_wrapper_registry_lookup(PsgWrapperRegistry *registry,
	const char *name, size_t size);


#ifdef __cplusplus
	} // extern "C"
#endif

#endif /* _PASSENGER_WRAPPER_REGISTRY_CBINDINGS_H_ */
