#include <stdio.h>

#include "stdio.h"

void clearerr(FILE* stream) {
    stream->flags &= ~(FILE_FLAG_ERROR | FILE_FLAG_EOF);
}