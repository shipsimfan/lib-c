#include <string.h>

char* strncat(char* dest, const char* src, size_t n) {
    size_t i;
    for (i = 0; dest[i]; i++)
        ;

    for (; *src && i < n; i++, src++)
        dest[i] = *src;

    dest[i] = 0;

    return dest;
}