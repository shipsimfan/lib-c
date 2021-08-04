#include <stdio.h>

size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    char* p = ptr;
    for(size_t i = 0; i < nmemb; i++) {
        for(size_t j = 0; j < size; j++) {
            if((*p = fgetc(stream)) < 0)
                return i;
            p++;
        }
    }

    return nmemb;
}