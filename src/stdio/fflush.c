#include <stdio.h>

#include <los.h>
#include "stdio.h"

int fflush(FILE* stream) {
    if (stream->flags & FILE_FLAG_WRITE) {
        switch(stream->type) {
            case STDIO_TYPE_CONSOLE: {
                if(stream->buffer_type == _IONBF) {
                    if(console_write_ch(stream->unbuffered_buffer) < 0) {
                        stream->flags |= FILE_FLAG_ERROR;
                        return EOF;
                    }
                    
                    return 0;
                }

                int64_t status = console_write(stream->buffer, stream->buffer_length);

                stream->buffer_length = 0;
                stream->buffer_offset = 0;

                if(status < 0) {
                    stream->flags |= FILE_FLAG_ERROR;
                    return EOF;
                }

                return 0;
            }

            case STDIO_TYPE_FILE: {
                if(stream->buffer_type == _IONBF) {
                    if(write_file(stream->descriptor, &stream->unbuffered_buffer, 1) < 0) {
                        stream->flags |= FILE_FLAG_ERROR;
                        return EOF;
                    }

                    return 0;
                }

                int64_t status = write_file(stream->descriptor, stream->buffer, stream->buffer_offset);

                stream->buffer_start += stream->buffer_offset;
                stream->buffer_length = 0;
                stream->buffer_offset = 0;

                if(status < 0) {
                    stream->flags |= FILE_FLAG_ERROR;
                    return EOF;
                }

                return 0;
            }
            
            default:
                stream->flags |= FILE_FLAG_ERROR;
                return EOF;
        }
    }

    if (stream->flags & FILE_FLAG_READ && stream->type == STDIO_TYPE_FILE && stream->buffer_type != _IONBF) {
        stream->buffer_start += stream->buffer_offset;
        stream->buffer_length = 0;
        stream->buffer_offset = 0;
    }

    return 0;
}