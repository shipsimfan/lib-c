#include <stdlib.h>

double strtod(const char* str, char** endptr) {
    double value = 0;
    double divider = 10;
    int decimal = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            char val = *str - '0';
            if (decimal) {
                value += val / divider;
                divider *= 10;
            } else {
                value *= 10;
                value += val;
            }
        } else if (*str == '.') {
            if (decimal)
                break;
            else
                decimal = 1;
        } else
            break;

        str++;
    }

    if (endptr)
        *endptr = (char*)str;

    return decimal;
}