#ifndef __SIGNAL_H
#define __SIGNAL_H

#define SIGKILL 0
#define SIGTERM 1
#define SIGABRT 2
#define SIGINT 3
#define SIGALRM 4

#define SIG_DFL ((void (*)(int))0)
#define SIG_ERR ((void (*)(int)) - 1)
#define SIG_IGN ((void (*)(int))1)

typedef int __sig_atomic_t;

extern void (*__signal_handlers[256])(int);

int raise(int sig);
void (*signal(int sig, void (*func)(int)))(int);

#endif