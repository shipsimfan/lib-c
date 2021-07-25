#include <string.h>

void* memchr(const void* str, int c, size_t n) {
    unsigned char ch = c;
    const unsigned char* ptr = str;

    for (size_t i = 0; i < n; i++, ptr++)
        if (*ptr == ch)
            return (void*)ptr;

    return NULL;
}