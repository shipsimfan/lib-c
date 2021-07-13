#ifndef __STDIO_INTERNAL_H
#define __STDIO_INTERNAL_H

#include <stdarg.h>

typedef void (*PrintfOutput)(char character);

int internal_printf(PrintfOutput output, const char* format, va_list arg);

#endif