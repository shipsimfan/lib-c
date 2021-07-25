#include <string.h>

size_t strcspn(const char* str1, const char* str2) {
    size_t len = 0;
    while (*str1) {
        for (const char* ptr = str2; *ptr; ptr++)
            if (*str1 == *ptr)
                return len;

        str1++;
        len++;
    }

    return len;
}