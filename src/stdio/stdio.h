#ifndef __STDIO_INTERNAL_H
#define __STDIO_INTERNAL_H

#include <stdarg.h>
#include <los/process.h>

#define FILE_FLAG_READ 1
#define FILE_FLAG_WRITE 2
#define FILE_FLAG_EOF 4
#define FILE_FLAG_ERROR 8

typedef struct UngetcNode_t {
    int c;
    struct UngetcNode_t* next;
} UngetcNode;

typedef int (*PrintfOutput)(int character, void* context);

int __internal_printf(PrintfOutput output, void* output_context, const char* format, va_list arg);
void __initialize_stdio(StandardIO* stdio);

#endif