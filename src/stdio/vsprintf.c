#include <stdio.h>

#include "stdio.h"

typedef struct {
    char* str;
} StringIterator;

int __append_string(int ch, StringIterator* iter) {
    if (*iter->str == NULL)
        return ch;

    *iter->str = ch;
    iter->str++;
    return ch;
}

int vsprintf(char* str, const char* format, va_list arg) {
    StringIterator iter = {str};
    return __internal_printf((PrintfOutput)__append_string, &iter, format, arg);
}