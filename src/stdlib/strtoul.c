#include <stdlib.h>

unsigned long int strtoul(const char* str, char** endptr, int base) {
    if (base < 2 || base > 36)
        return 0;

    base--;

    unsigned long int value = 0;
    while (*str) {
        if (base < 10) {
            if (*str >= '0' && *str <= '0' + base) {
                value *= base;
                value += *str - '0';
            } else
                break;
        } else {
            if (*str >= '0' && *str <= '9') {
                value *= base;
                value += *str - '0';
            } else if (*str >= 'a' && *str <= 'a' + base - 10) {
                value *= base;
                value += *str - 'a' + 10;
            } else if (*str >= 'A' && *str <= 'A' + base - 10) {
                value *= base;
                value += *str - 'A' + 10;
            } else
                break;
        }

        str++;
    }

    if (endptr)
        *endptr = (char*)str;
    return value;
}