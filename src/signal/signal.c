#include <signal.h>

#include <los/signal.h>

void (*signal(int sig, void (*func)(int)))(int) {
    if (sig > 255)
        return SIG_DFL;

    /*void (*ret)(int) = __signal_handlers[sig];
    __signal_handlers[sig] = func;

    if (func == SIG_IGN)
        set_signal_type(sig, SIGNAL_TYPE_IGNORE);
    else if (func == SIG_DFL) {
        if (sig == SIGKILL || sig == SIGTERM || sig == SIGABRT || sig == SIGINT)
            set_signal_type(sig, SIGNAL_TYPE_TERMINATE);
        else
            set_signal_type(sig, SIGNAL_TYPE_IGNORE);
    } else
        set_signal_type(sig, SIGNAL_TYPE_USERSPACE);

    return ret;*/
    return SIG_DFL;
}