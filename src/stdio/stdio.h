#ifndef __STDIO_INTERNAL_H
#define __STDIO_INTERNAL_H

#include <stdarg.h>
#include <los/process.h>

typedef int (*PrintfOutput)(int character, void* context);

int __internal_printf(PrintfOutput output, void* output_context, const char* format, va_list arg);
void __initialize_stdio(StandardIO* stdio);

#endif