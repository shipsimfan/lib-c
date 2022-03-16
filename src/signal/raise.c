#include <signal.h>

#include <los/signal.h>

int raise(int sig) {
    raise_self((u8)sig);
    return 0;
}
