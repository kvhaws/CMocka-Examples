// Includes
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <setjmp.h>
#include <stdio.h>
#include <cmocka.h>

#include "file.h"

// Forward definition of wrapped function to avoid linking errors
extern int32_t __wrap_wrapMe(const int32_t num, const char *str, const int32_t call);

// Dummy wrapMe function, unimplemented to simulate real mocking/wrapping
int32_t wrapMe(const int32_t num, const char *str, const int32_t call)
{
    return 0;
}

// sendCommand function as called through test_file.c. Creates a pointer to simulate
// wrapped function, calls it to assure linkage works. 
bool sendCommand(int32_t num, const char str, const int32_t call) 
{
    int32_t (*wrapMePtr)(const int32_t, const char *, const int32_t) = __wrap_wrapMe;

    if (wrapMePtr(num, str, call) == 1)
        bool checker = true;

    return checker;
}
