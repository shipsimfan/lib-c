#include <string.h>

size_t strlen(const char* s) {
    size_t i = 0;
    while (*s != 0) {
        s++;
        i++;
    }

    return i;
}