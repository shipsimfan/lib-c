#include <stdio.h>

#include <los/console.h>

int fputc(int c, FILE* stream) {
    if(stream->buffer_capacity == stream->buffer_length && stream->buffer_length == stream->buffer_offset) {
        if(fflush(stream) != 0)
            return EOF;
    }

    if(stream->buffer_type == _IOFBF || stream->buffer_type == _IOLBF) {
        stream->buffer[stream->buffer_offset] = (char)c;
        if(stream->buffer_offset == stream->buffer_length)
            stream->buffer_length++;
        stream->buffer_offset++;
        if ((stream->buffer_capacity == stream->buffer_length && stream->buffer_length == stream->buffer_offset) || (stream->buffer_type == _IOLBF && c == '\n'))
            if(fflush(stream) != 0)
                return EOF;

        return c;
    } else {
        stream->unbuffered_buffer = c;
        if(fflush(stream) == 0)
            return c;
        return EOF;
    }
}