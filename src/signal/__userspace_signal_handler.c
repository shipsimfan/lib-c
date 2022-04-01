#include <signal.h>

#include <los/types.h>

void (*__signal_handlers[256])(int);

void __userspace_signal_handler(u8 signal_number) {
    void (*handler)(int) = __signal_handlers[signal_number];

    if (handler != SIG_DFL && handler != SIG_IGN)
        handler(signal_number);
}