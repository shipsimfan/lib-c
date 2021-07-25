#include <string.h>

char* strpbrk(const char* str1, const char* str2) {
    while (*str1) {
        for (const char* ptr = str2; *ptr; ptr++)
            if (*str1 == *ptr)
                return (char*)str1;

        str1++;
    }

    return NULL;
}