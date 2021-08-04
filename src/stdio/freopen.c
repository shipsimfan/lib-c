#include <stdio.h>

FILE* freopen(const char* filename, const char* mode, FILE* stream) {
    fclose(stream);

    if(filename != NULL) 
        return fopen(filename, mode);
    return NULL;
}