#include <string.h>

char* strcat(char* dest, const char* src) {
    size_t i;
    for (i = 0; dest[i]; i++)
        ;

    for (; *src; i++, src++)
        dest[i] = *src;

    dest[i] = 0;

    return dest;
}