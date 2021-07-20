#include <string.h>

char* strcpy(char* dest, const char* src) {
    size_t i;
    for (i = 0; *src; i++, src++)
        dest[i] = *src;

    dest[i] = 0;

    return dest;
}