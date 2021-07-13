#include <stdlib.h>

size_t top = 0x10000000;

void* malloc(size_t size) {
    void* ret = (void*)top;
    top += size;
    return ret;
}