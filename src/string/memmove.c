#include <string.h>

#include <stdlib.h>

void* memmove(void* dest, const void* src, size_t n) {
    void* intermediate = malloc(n);

    memcpy(intermediate, src, n);
    memcpy(dest, intermediate, n);

    free(intermediate);

    return dest;
}
