#include <stdio.h>

int fsetpos(FILE* stream, const fpos_t* pos) {
    if(fseek(stream, *pos, SEEK_SET) < 0)
        return EOF;
    
    return 0;
}