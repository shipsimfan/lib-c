#include <stdio.h>

#include "stdio.h"

int feof(FILE* stream) {
    return stream->flags & FILE_FLAG_EOF;
}