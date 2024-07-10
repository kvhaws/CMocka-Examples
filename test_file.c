// Includes
#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>

#include "file.h"

// Forward definition of soon to be wrapped function
#define wrapMe __wrap_wrapMe

// Wrapped function of above wrapMe. Returns the mock type, checks if the function was fed the correct argument.
int32_t __wrap_wrapMe(const int32_t *num, const char *str, const int32_t *call)
{
   check_expected_ptr(num);
   check_expected_ptr(str);
   check_expected_ptr(call);

   return mock_type(int32_t);
}

// Tells the wrapped function what parameters to accept and what to return, then checks that 
// by routing it through a function in another file, file.c.
static void test_wrap(void **state)
{
    int32_t number = 0; 
    char character = 'a';
    int32_t callNum = 0;

    expect_any(__wrap_wrapMe, num);
    expect_any(__wrap_wrapMe, str);
    expect_any(__wrap_wrapMe, call);

    will_return(__wrap_wrapMe, 1);
    assert_true(sendCommand(number, character, callNum));
}

// Runs each test
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_wrap)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
