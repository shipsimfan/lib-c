#include <stdlib.h>

#include <los/process.h>

void exit(int status) {
    exit_process(status);
    while (1)
        ;
}