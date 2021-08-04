#include <stdio.h>

void setbuf(FILE* stream, char* buffer) {
    setvbuf(stream, buffer, _IOFBF, BUFSIZ);
}