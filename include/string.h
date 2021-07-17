#ifndef __STRING_H
#define __STRING_H

#include <stddef.h>

size_t strlen(const char* s);
size_t strnlen(const char* s, size_t maxlen);
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n);

char* strtok(char* str, const char* delim);
char* strtok_r(char* str, const char* delim, char** saveptr);

#endif