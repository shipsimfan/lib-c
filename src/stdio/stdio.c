#include <stdio.h>
#include "stdio.h"

#include <stdlib.h>
#include <los/filesystem.h>

FILE __stdout;
FILE __stderr;
FILE __stdin;

void __initialize_stdio(StandardIO* stdio) {
    // Initialize stdout
    __stdout.type = stdio->stdout_type;
    __stdout.descriptor = stdio->stdout_desc;
    if(__stdout.type == STDIO_TYPE_CONSOLE)
        __stdout.buffer_type = _IOLBF;
    else
        __stdout.buffer_type = _IOFBF;
    __stdout.buffer = (char*)malloc(BUFSIZ);
    __stdout.buffer_capacity = BUFSIZ;
    __stdout.buffer_length = 0;
    __stdout.buffer_offset = 0;
    if(__stdout.type == STDIO_TYPE_FILE)
        __stdout.buffer_start = tell_file(__stdout.descriptor);
    else
        __stdout.buffer_start = 0;
    __stdout.flags = FILE_FLAG_WRITE;
    __stdout.ungetc = NULL;

    // Initialize stderr
    __stderr.type = stdio->stderr_type;
    __stderr.descriptor = stdio->stderr_desc;
    __stderr.buffer_type = _IONBF;
    __stderr.buffer = NULL;
    __stderr.buffer_capacity = 1;
    __stderr.buffer_length = 0;
    __stderr.buffer_offset = 0;
    __stderr.buffer_start = 0;
    __stderr.flags = FILE_FLAG_WRITE;
    __stdout.ungetc = NULL;

    // Initialize stdin
    __stdin.type = stdio->stdin_type;
    __stdin.descriptor = stdio->stdin_desc;
    if(__stdin.type == STDIO_TYPE_CONSOLE)
        __stdin.buffer_type = _IOLBF;
    else
        __stdin.buffer_type = _IOFBF;
    __stdin.buffer = (char*)malloc(BUFSIZ);
    __stdin.buffer_capacity = BUFSIZ;
    __stdin.buffer_length = 0;
    __stdin.buffer_offset = 0;
    if(__stdin.type == STDIO_TYPE_FILE)
        __stdin.buffer_start = tell_file(__stdin.descriptor);
    else
        __stdin.buffer_start = 0;
    __stdin.flags = FILE_FLAG_READ;
    __stdin.ungetc = NULL;
}
