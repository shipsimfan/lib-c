#include <stdio.h>

#include <los.h>

int fflush(FILE* stream) {
    switch(stream->type) {
        case STDIO_TYPE_CONSOLE: {
            if(stream->buffer_type == _IONBF) {
                if(console_write_ch(stream->unbuffered_buffer) < 0)
                    return EOF;
                
                return 0;
            }

            int64_t status = console_write(stream->buffer, stream->buffer_length);

            stream->buffer_length = 0;

            if(status < 0)
                return EOF;

            return 0;
        }

        case STDIO_TYPE_FILE: {
            if(stream->buffer_type == _IONBF) {
                if(write_file(stream->descriptor, &stream->unbuffered_buffer, 1) < 0)
                    return EOF;

                return 0;
            }

            int64_t status = write_file(stream->descriptor, stream->buffer, stream->buffer_length);

            stream->buffer_length = 0;

            if(status < 0)
                return EOF;

            return 0;
        }
        
        default:
            return EOF;
    }
}