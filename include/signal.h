#ifndef __SIGNAL_H
#define __SIGNAL_H

#define SIGABRT 0
#define SIGFPE 1
#define SIGILL 2
#define SIGINT 3
#define SIGSEGV 4
#define SIGTERM 5
#define SIGKILL 6

#define SIG_DFL ((void (*)(int))0)
#define SIG_ERR ((void (*)(int)) - 1)
#define SIG_IGN ((void (*)(int))1)

typedef int __sig_atomic_t;

int raise(int sig);

#endif