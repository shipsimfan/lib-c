#include <string.h>

size_t strspn(const char* str1, const char* str2) {
    size_t len = 0;
    while (*str1) {
        int ok = 0;
        for (const char* ptr = str2; *ptr; ptr++) {
            if (*str1 == *ptr) {
                ok = 1;
                break;
            }
        }

        if (!ok)
            return len;

        str1++;
        len++;
    }

    return len;
}