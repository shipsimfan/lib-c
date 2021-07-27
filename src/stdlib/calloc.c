#include <stdlib.h>

#include <string.h>

void* calloc(size_t nitems, size_t size) {
    size_t alloc_size = nitems * size;
    if (alloc_size == 0 || alloc_size < nitems || alloc_size < size)
        return NULL;

    void* ptr = malloc(alloc_size);

    memset(ptr, 0, alloc_size);

    return ptr;
}