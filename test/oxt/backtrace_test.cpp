#include "../tut/tut.h"
#include "counter.hpp"
#include <oxt/backtrace.hpp>
#include <oxt/tracable_exception.hpp>
#include <oxt/thread.hpp>

using namespace oxt;
using namespace std;

namespace tut {
	struct backtrace_test {
	};

	DEFINE_TEST_GROUP(backtrace_test);

	TEST_METHOD(1) {
		set_test_name("TRACE_POINT() and tracable_exception");

		struct {
			void foo() {
				TRACE_POINT();
				bar();
			}

			void bar() {
				TRACE_POINT();
				baz();
			}

			void baz() {
				TRACE_POINT();
				throw tracable_exception();
			}
		} object;

		try {
			object.foo();
			fail("tracable_exception expected.");
		} catch (const tracable_exception &e) {
			ensure("Backtrace contains foo()",
				e.backtrace().find("foo()") != string::npos);
			ensure("Backtrace contains bar()",
				e.backtrace().find("bar()") != string::npos);
			ensure("Backtrace contains baz()",
				e.backtrace().find("baz()") != string::npos);
		}
	}

	TEST_METHOD(2) {
		set_test_name("oxt::thread's backtrace support works");

		CounterPtr parent_counter = Counter::create_ptr();
		CounterPtr child_counter  = Counter::create_ptr();
		oxt::thread foo_thread([&] {
			TRACE_POINT_WITH_NAME("foo_thread");
			child_counter->increment();    // Tell parent that we've created the trace point.
			parent_counter->wait_until(1); // Wait until parent thread says we can exit.
		});
		oxt::thread bar_thread([&] {
			TRACE_POINT_WITH_NAME("bar_thread");
			child_counter->increment();    // Tell parent that we've created the trace point.
			parent_counter->wait_until(1); // Wait until parent thread says we can exit.
		});

		// Wait until all threads have created trace points.
		child_counter->wait_until(2);

		ensure("Foo thread's backtrace contains foo()",
			foo_thread.backtrace().find("foo") != string::npos);
		ensure("Foo thread's backtrace doesn't contain bar()",
			foo_thread.backtrace().find("bar") == string::npos);
		ensure("Bar thread's backtrace contains bar()",
			bar_thread.backtrace().find("bar") != string::npos);
		ensure("Bar thread's backtrace doesn't contain foo()",
			bar_thread.backtrace().find("foo") == string::npos);

		string all_backtraces(oxt::thread::all_backtraces());
		ensure(all_backtraces.find("foo") != string::npos);
		ensure(all_backtraces.find("bar") != string::npos);

		parent_counter->increment(); // Tell threads to quit.
		foo_thread.join();
		bar_thread.join();
	}

	TEST_METHOD(3) {
		set_test_name("tracable_exception empty backtrace");

		tracable_exception empty((tracable_exception::no_backtrace()));
		ensure_equals("Empty backtrace is empty",
			empty.backtrace(), "     (empty)");
	}

	TEST_METHOD(4) {
		set_test_name("tracable_exception copy constructor");

		struct {
			void foo() {
				TRACE_POINT();
				throw tracable_exception();
			}
		} object;

		try {
			object.foo();
			fail("tracable_exception expected.");
		} catch (const tracable_exception &e) {
			// Create a copy using the copy constructor
			tracable_exception copy(e);

			// Verify the copy has the same backtrace information
			ensure_equals("Copy constructor preserves backtrace",
				copy.backtrace(), e.backtrace());
			ensure("Backtrace contains foo()",
				copy.backtrace().find("foo()") != string::npos);
		}

		// Copy empty backtrace
		tracable_exception empty((tracable_exception::no_backtrace()));
		tracable_exception empty_copy(empty);
		ensure_equals("Copy of empty backtrace is also empty",
			empty_copy.backtrace(), empty.backtrace());
	}

	TEST_METHOD(5) {
		set_test_name("tracable_exception assignment operator");

		struct {
			void foo() {
				TRACE_POINT();
				throw tracable_exception();
			}
		} object;

		// Test copy constructor
		try {
			object.foo();
			fail("tracable_exception expected.");
		} catch (const tracable_exception &e) {
			// Create another exception with a different backtrace
			tracable_exception another;

			// Test assignment operator on non-empty backtrace
			another = e;
			ensure_equals("Assignment operator preserves backtrace",
				another.backtrace(), e.backtrace());
			ensure("Assigned backtrace contains foo()",
				another.backtrace().find("foo()") != string::npos);

			// Test assignment operator on empty backtrace
			tracable_exception empty((tracable_exception::no_backtrace()));
			another = empty;
			ensure_equals("Assignment of empty backtrace works",
				another.backtrace(), "     (empty)");
		}
	}
}

