#include <stdio.h>

#include <stdlib.h>

int setvbuf(FILE* stream, char* buffer, int mode, size_t size) {
    free(stream->buffer);

    stream->buffer_type = mode;
    stream->buffer = buffer;
    if(mode == _IONBF)
        stream->buffer_capacity = 1;
    else
        stream->buffer_capacity = size;
    stream->buffer_length = 0;
    stream->buffer_offset = 0;

    return 0;
}