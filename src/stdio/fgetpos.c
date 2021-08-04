#include <stdio.h>

int fgetpos(FILE* stream, fpos_t* pos) {
    *pos = ftell(stream);
    if(*pos < 0)
        return -1;
    return 0;
}