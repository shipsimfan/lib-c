#ifndef __STDLIB_H
#define __STDLIB_H

#include <stddef.h>

extern char** environ;

void exit(int status);

void* malloc(size_t size);
void free(void* ptr);

int setenv(const char* name, const char* value, int overwrite);
int unsetenv(const char* name);
char* getenv(const char* name);

#endif