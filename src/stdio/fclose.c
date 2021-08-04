#include <stdio.h>

#include <los/process.h>
#include <stdlib.h>
#include <los/filesystem.h>
#include "stdio.h"

int fclose(FILE* stream) {
    // Flush the stream
    if(fflush(stream) < 0)
        return EOF;

    // Free the buffer
    free(stream->buffer);

    // Free the ungetc queue
    UngetcNode* current_node = stream->ungetc;
    while(current_node != NULL) {
        UngetcNode* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    // Close the descriptor
    switch(stream->type) {
    case STDIO_TYPE_FILE:
        close_file(stream->descriptor);
        break;

    default:
        break;
    }

    // Free the file
    if(stream != stdout && stream != stderr && stream != stdin)
        free(stream);

    return 0;
}