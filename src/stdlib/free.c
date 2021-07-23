#include <stdlib.h>

#include <los/memory.h>

void free(void* ptr) { free_memory(ptr); }