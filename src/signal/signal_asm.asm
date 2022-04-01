EXTERN __userspace_signal_handler

GLOBAL __userspace_signal_handler_asm
__userspace_signal_handler_asm:
    call __userspace_signal_handler

    ; Return to normal execution
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rbp
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    popfq

    ret