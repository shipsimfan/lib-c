EXTERN main
EXTERN exit

GLOBAL _start
_start:
	mov rsp, 0x7FFFFFFFFFF0

	; Get argv and argc out of context
	mov rcx, [rdi]
	add rdi, 8
	mov rsi, [rdi]
	mov rdi, rcx

	call main

	mov rdi, rax
	call exit
