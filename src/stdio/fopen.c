#include <stdio.h>

#include "stdio.h"
#include <los/filesystem.h>
#include <los/process.h>
#include <stdlib.h>
#include <string.h>

FILE* fopen(const char* filename, const char* mode) {
    FILE* new_file = (FILE*)malloc(sizeof(FILE));

    usize flags;

    if (strcmp(mode, "r") == 0)
        flags = OPEN_READ;
    else if (strcmp(mode, "w") == 0)
        flags = OPEN_WRITE | OPEN_CREATE | OPEN_TRUNCATE;
    else if (strcmp(mode, "a") == 0)
        flags = OPEN_WRITE | OPEN_CREATE | OPEN_APPEND;
    else if (strcmp(mode, "r+") == 0)
        flags = OPEN_READWRITE;
    else if (strcmp(mode, "w+") == 0)
        flags = OPEN_READWRITE | OPEN_CREATE | OPEN_TRUNCATE;
    else if (strcmp(mode, "a+") == 0)
        flags = OPEN_READWRITE | OPEN_CREATE | OPEN_APPEND;
    else
        return NULL;

    new_file->type = STDIO_TYPE_FILE;
    new_file->descriptor = open_file(filename, flags);
    if (new_file->descriptor < 0) {
        free(new_file);
        return NULL;
    }

    int new_file_flags = 0;
    if (flags & OPEN_WRITE)
        new_file_flags |= FILE_FLAG_WRITE;
    if (flags & OPEN_READ)
        new_file_flags |= FILE_FLAG_READ;

    new_file->buffer_type = _IOFBF;
    new_file->buffer = (char*)malloc(BUFSIZ);
    new_file->buffer_capacity = BUFSIZ;
    new_file->buffer_length = 0;
    new_file->buffer_offset = 0;
    new_file->buffer_start = 0;
    new_file->flags = new_file_flags;
    new_file->ungetc = NULL;

    return new_file;
}