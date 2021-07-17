#include <string.h>

char* STRTOK_PTR = NULL;

char* strtok(char* str, const char* delim) { return strtok_r(str, delim, &STRTOK_PTR); }