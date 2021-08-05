#include <stdio.h>

#include "stdio.h"
#include <stdlib.h>
#include <los/process.h>
#include <los/filesystem.h>

int fseek(FILE* stream, long int offset, int whence) {
    if(stream->type == STDIO_TYPE_FILE) {
        if(fflush(stream) < 0)
            return EOF;

        if(seek_file(stream->descriptor, offset, whence) < 0)
            return EOF;

        stream->buffer_start = tell_file(stream->descriptor);
        if(stream->buffer_start < 0)
            return EOF;

        // Clear ungetc queue
        UngetcNode* current_node = stream->ungetc;
        stream->ungetc = NULL;
        while(current_node != NULL) {
            UngetcNode* next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }

        return 0;
    }

    return EOF;
}