#include <stdlib.h>

#include <los/process.h>

extern void _fini();

void exit(int status) {
    _fini();
    exit_process(status);
    while (1)
        ;
}