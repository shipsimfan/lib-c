#ifndef __STDIO_H
#define __STDIO_H

#include <stdarg.h>

typedef __SIZE_TYPE__ size_t;
typedef struct {
    unsigned long type;
    long descriptor;
    int buffer_type;
    char* buffer;
    int buffer_capacity;
    int buffer_length;
    int unbuffered_buffer;
} FILE;
typedef __INTPTR_TYPE__ fpos_t;

#define NULL ((void*)0)
#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2
#define BUFSIZ 4096
#define EOF -1
#define FOPEN_MAX 256
#define FILENAME_MAX 4096
#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0
#define stderr (&__stderr)
#define stdout (&__stdout)

extern FILE __stderr;
extern FILE __stdout;

int fflush(FILE* stream);
void setbuf(FILE* stream, char* buffer);
int setvbuf(FILE* stream, char* buffer, int mode, size_t size);
size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream);
int fprintf(FILE* stream, const char* format, ...);
int printf(const char* format, ...);
int sprintf(char* str, const char* format, ...);
int vfprintf(FILE* stream, const char* format, va_list arg);
#define vprintf(format, arg) vfprintf(stdout, format, arg)
int vsprintf(char* str, const char* format, va_list arg);
int fputc(int c, FILE* stream);
int fputs(const char* str, FILE* stream);
#define putc(c, stream) fputc(c, stream)
#define putchar(c) fputc(c, stdout)
#define puts(str) fputs(str, stdout)
void perror(const char* str);

#endif