#include <string.h>

char* strtok_r(char* str, const char* delim, char** saveptr) {
    if (str == NULL)
        str = *saveptr;

    // Skip begging delimeters
    while (*str) {
        const char* d_ptr = delim;
        int delim = 0;
        while (*d_ptr) {
            if (*d_ptr == *str) {
                delim = 1;
                break;
            }
            d_ptr++;
        }

        if (!delim)
            break;

        str++;
    }

    if (*str == 0) {
        return NULL;
    }

    char* start = str;

    // Scan for next delimeter
    while (*str) {
        const char* d_ptr = delim;
        while (*d_ptr) {
            if (*str == *d_ptr) {
                *str = 0;
                str++;
                *saveptr = str;
                return start;
            }
            d_ptr++;
        }

        str++;
    }

    *saveptr = str;
    return start;
}