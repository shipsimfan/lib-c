#include <stdlib.h>

#include <los/memory.h>
#include <string.h>

void* realloc(void* ptr, size_t size) {
    void* new_ptr = malloc(size);
    size_t old_size = get_allocation_size(ptr);

    size_t copy_size = size;
    if (copy_size > old_size)
        copy_size = old_size;

    memcpy(new_ptr, ptr, copy_size);

    free(ptr);

    return new_ptr;
}