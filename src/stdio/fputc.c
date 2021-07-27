#include <stdio.h>

#include <los/console.h>

int fputc(int c, FILE* stream) { return console_write((char)c); }