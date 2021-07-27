#include <stdlib.h>

long int strtol(const char* str, char** endptr, int base) {
    long int modifier = 1;
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            modifier = -1;

        str++;
    }

    long int value = (long int)strtoul(str, endptr, base);
    return value * modifier;
}