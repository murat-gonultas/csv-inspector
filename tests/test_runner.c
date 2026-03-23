#include <stdio.h>
#include <stdlib.h>

int test_core(void);

int main(void) {
    int fail = 0;

    fail |= test_core();

    if (fail) {
        fprintf(stderr, "TESTS FAILED\n");
        return EXIT_FAILURE;
    }

    printf("ALL TESTS PASSED\n");
    return EXIT_SUCCESS;
}