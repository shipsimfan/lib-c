#include <string.h>

size_t strnlen(const char* s, size_t maxlen) {
    size_t i = 0;
    while (*s != 0 && i < maxlen) {
        s++;
        i++;
    }

    return i;
}