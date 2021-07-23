#include <stdlib.h>

#include <los/memory.h>

void* malloc(size_t size) { return allocate_memory(size); }