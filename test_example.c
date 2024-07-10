// Includes
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

// Declarations
int32_t num = 16;
int32_t num2 = 16;


// Example test function -- checks if two numbers are equal from their declarations
static void test_example_true(void **state) 
{
    assert_int_equal(num, num2);
}

// Example test function -- checks if two numbers are equal as given
static void test_example_false(void **state) 
{
    assert_int_equal(2, 2);
}

// Example test function -- asserts that the two given numbers are indeed not equal, rendering the statement false
static void test_example_bool(void **state) 
{    
    assert_false(5 == 6);
}

// Example test function -- checks if the first number is in the range given by the second and third integers
static void test_example_range(void **state) 
{
    assert_in_range(2, 1, 7);
}

// Function to test the assertion in test_return, taking in the mocked value
int func()
{
    int r = return_int();

    return r;
}

// Returns the mocked value as given by will_return
int return_int(void)
{
    return (int)mock();
}

// Function to test the will_return and following assertion in test_return
static void test_return(void **state) {

    will_return(return_int, 42);

    assert_int_equal(func(), 42);
}

// Runs each test
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_example_true),
        cmocka_unit_test(test_example_false),
        cmocka_unit_test(test_example_bool),
        cmocka_unit_test(test_example_range),
        cmocka_unit_test(test_return)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
