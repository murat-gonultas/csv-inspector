#include "core.h"

int core_add(int a, int b) {
    return a + b;
}

size_t core_strlen_safe(const char *s) {
    size_t n = 0;

    if (s == NULL) {
        return 0;
    }

    while (s[n] != '\0') {
        n++;
    }

    return n;
}