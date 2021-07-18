#include <stdlib.h>

size_t top = 0x10000000;

void* malloc(size_t size) {
    void* ret = (void*)top;

    if (size % 8 != 0) {
        size -= size % 8;
        size += 8;
    }

    top += size;
    return ret;
}