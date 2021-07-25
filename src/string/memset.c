#include <string.h>

void* memset(void* str, int c, size_t n) {
    unsigned char ch = c;
    unsigned char* ptr = str;

    for (size_t i = 0; i < n; i++, ptr++)
        *ptr = ch;

    return str;
}