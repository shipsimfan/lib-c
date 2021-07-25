#include <string.h>

void* memcpy(void* dest, const void* src, size_t n) {
    char* ptr1 = dest;
    const char* ptr2 = src;
    for (size_t i = 0; i < n; i++, ptr1++, ptr2++)
        *ptr1 = *ptr2;

    return dest;
}