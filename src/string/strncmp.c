#include <string.h>

int strncmp(const char* s1, const char* s2, size_t n) {
    for (size_t i = 0; i < n && *s1 && *s1 == *s2; i++, s1++, s2++) {
    }

    return *s1 - *s2;
}