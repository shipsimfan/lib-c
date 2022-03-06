#include <signal.h>

#include <los/signal.h>

int raise(int sig) { return (int)raise_self((u8)sig); }
