#include <stdio.h>

#include <errno.h>
#include <string.h>

void perror(const char* str) {
    int err = errno;

    if (str && *str) {
        fputs(str, stderr);
        fputs(": ", stderr);
    }

    fputs(strerror(err), stderr);
    fputc('\n', stderr);
}