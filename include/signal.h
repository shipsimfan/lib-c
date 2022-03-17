#ifndef __SIGNAL_H
#define __SIGNAL_H

#define SIGKILL 0
#define SIGTERM 1
#define SIGABRT 2
#define SIGINT 3

#define SIG_DFL ((void (*)(int))0)
#define SIG_ERR ((void (*)(int)) - 1)
#define SIG_IGN ((void (*)(int))1)

typedef int __sig_atomic_t;

int raise(int sig);

#endif