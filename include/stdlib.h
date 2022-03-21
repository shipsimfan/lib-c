#ifndef __STDLIB_H
#define __STDLIB_H

typedef __SIZE_TYPE__ size_t;
typedef struct {
    int quot;
    int rem;
} div_t;
typedef struct {
    long int quot;
    long int rem;
} ldiv_t;

#ifndef NULL
#define NULL ((void*)0)
#endif

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

extern char** environ;

#define atof(str) strtod(str, NULL)
#define atoi(str) ((int)strtol(str, NULL, 10))
#define atol(str) strtol(str, NULL, 10)
double strtod(const char* str, char** endptr);
long int strtol(const char* str, char** endptr, int base);
unsigned long int strtoul(const char* str, char** endptr, int base);
void* calloc(size_t nitems, size_t size);
void free(void* ptr);
void* malloc(size_t size);
void* realloc(void* ptr, size_t size);
__attribute__((noreturn)) void abort();
__attribute__((noreturn)) void exit(int status);
char* getenv(const char* name);
int setenv(const char* name, const char* value, int overwrite);
int unsetenv(const char* name);
#define abs(x) ((int)labs(x))
div_t div(int numer, int demon);
long int labs(long int x);
ldiv_t ldiv(long int numer, long int demon);

#endif