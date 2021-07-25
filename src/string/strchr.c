#include <string.h>

char* strchr(const char* str, int c) {
    char ch = c;
    while (*str) {
        if (*str == ch)
            return (char*)str;

        str++;
    }

    return NULL;
}