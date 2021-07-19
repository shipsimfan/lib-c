#ifndef __STDIO_INTERNAL_H
#define __STDIO_INTERNAL_H

#include <stdarg.h>
#include <stdint.h>

typedef int64_t (*PrintfOutput)(char character);

int internal_printf(PrintfOutput output, const char* format, va_list arg);

#endif