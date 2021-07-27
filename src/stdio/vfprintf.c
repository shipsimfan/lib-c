#include <stdio.h>

#include "stdio.h"

int vfprintf(FILE* stream, const char* format, va_list arg) { return __internal_printf((PrintfOutput)fputc, stream, format, arg); }