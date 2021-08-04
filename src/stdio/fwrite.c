#include <stdio.h>

size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream) {
    const char* p = ptr;
    for(size_t i = 0; i < nmemb; i++) {
        for(size_t j = 0; j < size; j++) {
            if(fputc(*p, stream) < 0)
                return i;
            p++;
        }
    }

    return nmemb;
}