#include <stdio.h>

int fputs(const char* str, FILE* stream) {
    while (*str) {
        if (fputc(*str, stream) < 0)
            return EOF;

        str++;
    }

    return 0;
}