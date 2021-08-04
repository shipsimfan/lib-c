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
    int buffer_offset;
    long buffer_start;
    int unbuffered_buffer;
    int flags;
    void* ungetc;
} FILE;
typedef long fpos_t;

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
#define stdin (&__stdin)

extern FILE __stderr;
extern FILE __stdout;
extern FILE __stdin;

int fclose(FILE* stream);
void clearerr(FILE* stream);
int feof(FILE* stream);
int ferror(FILE* stream);
int fflush(FILE* stream);
int fgetpos(FILE* stream, fpos_t* pos);
FILE* fopen(const char* filename, const char* mode);
size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream);
FILE* freopen(const char* filename, const char* mode, FILE* stream);
int fseek(FILE* stream, long int offset, int whence);
int fsetpos(FILE* stream, const fpos_t* pos);
long int ftell(FILE* stream);
size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream);
int remove(const char* filename);
//int rename(const char* old_filename, const char* new_filename);
void rewind(FILE* stream);
void setbuf(FILE* stream, char* buffer);
int setvbuf(FILE* stream, char* buffer, int mode, size_t size);
// FILE* tmpfile();
// char* tmpnam(char* str);
int fprintf(FILE* stream, const char* format, ...);
int printf(const char* format, ...);
int sprintf(char* str, const char* format, ...);
int vfprintf(FILE* stream, const char* format, va_list arg);
#define vprintf(format, arg) vfprintf(stdout, format, arg)
int vsprintf(char* str, const char* format, va_list arg);
// int fscanf(FILE* stream, const char* format, ...);
// int scanf(const char* format, ...);
// int sscanf(const char* str, const char* format, ...);
int fgetc(FILE* stream);
char* fgets(char* str, int n, FILE* stream);
int fputc(int c, FILE* stream);
int fputs(const char* str, FILE* stream);
#define getc(stream) fgetc(stream)
#define getchar() fgetc(stdin)
#define gets(str) fgets(str, __INT_MAX__, stdin)
#define putc(c, stream) fputc(c, stream)
#define putchar(c) fputc(c, stdout)
#define puts(str) fputs(str, stdout)
int ungetc(int c, FILE* stream);
void perror(const char* str);

#endif