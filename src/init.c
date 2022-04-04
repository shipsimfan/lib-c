#include "stdio/stdio.h"

#include <los/signal.h>
#include <signal.h>

extern void __userspace_signal_handler_asm(u8 signal_number,
                                           SignalContext context);

void __initialize_lib_c(StandardIO* stdio) {
    // Initialize stdio
    __initialize_stdio(stdio);

    // Set signal handler
    for (int i = 0; i < 256; i++)
        __signal_handlers[i] = SIG_DFL;
    set_userspace_signal_handler(__userspace_signal_handler_asm);
}