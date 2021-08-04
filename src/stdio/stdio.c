#include <stdio.h>
#include "stdio.h"

#include <stdlib.h>

FILE __stdout;
FILE __stderr;

void __initialize_stdio(StandardIO* stdio) {
    // Initialize stdout
    __stdout.type = stdio->stdout_type;
    __stdout.descriptor = stdio->stdout_desc;
    if(__stdout.type == STDIO_TYPE_CONSOLE)
        __stdout.buffer_type = _IOLBF;
    else
        __stdout.buffer_type = _IOFBF;

    __stdout.buffer = (char*)malloc(BUFSIZ + 1);
    __stdout.buffer_capacity = BUFSIZ;
    __stdout.buffer_length = 0;

    // Initialize stderr
    __stderr.type = stdio->stderr_type;
    __stderr.descriptor = stdio->stderr_desc;
    __stderr.buffer_type = _IONBF;
    __stderr.buffer = NULL;
    __stderr.buffer_capacity = 1;
    __stderr.buffer_length = 0;
}
