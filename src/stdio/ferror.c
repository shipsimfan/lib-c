#include <stdio.h>

#include "stdio.h"

int ferror(FILE* stream) {
    return stream->flags & FILE_FLAG_ERROR;
}