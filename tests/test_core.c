#include <stdio.h>
#include <stddef.h>

#include "core.h"

#define ASSERT_TRUE(cond)                          \
    do {                                           \
        if (!(cond)) {                             \
            fprintf(stderr,                        \
                    "ASSERT FAILED: %s (%s:%d)\n", \
                    #cond,                         \
                    __FILE__,                      \
                    __LINE__);                     \
            return 1;                              \
        }                                          \
    } while (0)

int test_core(void) {
    ASSERT_TRUE(core_add(1, 2) == 3);
    ASSERT_TRUE(core_add(-1, 1) == 0);
    ASSERT_TRUE(core_strlen_safe("abc") == 3);
    ASSERT_TRUE(core_strlen_safe(NULL) == 0);

    return 0;
}