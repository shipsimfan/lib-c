#include <stdlib.h>

#include <los/thread.h>

void exit(int status) {
    exit_thread(status);
    while (1)
        ;
}