EXTERN main
EXTERN exit

GLOBAL _start
_start:
	mov rsp, 0x7FFFFFFFFFF0

	call main

	mov rdi, rax
	call exit
