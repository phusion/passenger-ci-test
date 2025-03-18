# C++ testing guide

C++ tests use a modified version of the [Tut test framework](https://mrzechonek.github.io/tut-framework/).

Test files are placed in test/cxx/SomethingTest.cpp.

Example:

```c++
#include <TestSupport.h> // Always include this
#include <Something.h> // The class to test

// Always use these namespaces
using namespace std;
using namespace boost;
using namespace Passenger;

namespace tut {
    // Each test suite has a corresponding context struct, created and
    // deleted for every test case. You can put test case-local state here.
    struct SomethingTest: public TestBase {
        Something something;
    };

    TEST_METHOD(1) {
        set_test_name("Description for test 1");

        // Test logic here

        ensure_equals("Description for assertion 1", 1, something.foo());
        ensure_equals("Description for assertion 2", 2, something.bar());
    }

    TEST_METHOD(2) {
        set_test_name("Description for test 2");

        // Test logic here
    }
}
```

Available assertions:

 - `ensure([description,] bool)` — Asserts argument is true.
 - `ensure_not([description,] bool)`
 - `ensure_equals([description,] actual, expected)` — Asserts `actual == expected`.
 - `ensure_not_equals([description,] actual, expected)`
 - `ensure_gt(description, a, b)` — Asserts `a > b`.
 - `ensure_distance([description,] a, b, d)` — Asserts the distance between `a` and `b` is <= `d`.
 - `fail(description)` — Fails the test case.

Special assertions for multithreaded code:

 - `EVENTUALLY(deadlineSeconds, code)` — Asserts that "something eventually happens".

   Runs `code` in a loop, sleeping for 10 msec each time, until code set `result = true` or timeout.

   Example:

   ```c++
   EVENTUALLY(5,
     result = fileExists("foo.txt");
   );
   ```

   Notes:

    - `code` is in a new lexical context, so defining variables there is fine.
    - Since EVENTUALLY is for multithreaded use cases, remember to synchronize access to shared state.

- `EVENTUALLY2(deadlineMsec, sleeptimeMsec, code)` — Same as EVENTUALLY but with finer timing customization.

- `SHOULD_NEVER_HAPPEN(deadlineMsec, code)` — Asserts that "something should never happen".

  Runs `code` in a loop for `deadlineMsec`. If `code` sets `result = true`, the test fails.

  Example:

  ```c++
  SHOULD_NEVER_HAPPEN(1000,
    result = checkSocketDisconnected();
  );
  ```

  The notes for `EVENTUALLY()` also apply here.
