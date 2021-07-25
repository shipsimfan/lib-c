#include <string.h>

int memcmp(const void* str1, const void* str2, size_t n) {
    const char* ptr1 = str1;
    const char* ptr2 = str2;
    for (size_t i = 0; *ptr1 && *ptr1 == *ptr2 && i < n; i++, ptr1++, ptr2++)
        ;

    return *ptr1 - *ptr2;
}