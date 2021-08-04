#include <stdio.h>

#include <los/process.h>

long int ftell(FILE* stream) {
    if(stream->type == STDIO_TYPE_FILE) {
        long int ret = tell_file(stream->descriptor);

        if(ret < 0)
            return EOF;

        return ret;
    }

    return EOF;
}