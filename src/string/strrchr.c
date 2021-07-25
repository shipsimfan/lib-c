#include <string.h>

char* strrchr(const char* str, int c) {
    char* last = NULL;
    char ch = c;

    while (*str) {
        if (*str == ch)
            last = (char*)str;

        str++;
    }

    return last;
}