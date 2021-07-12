EXTERN main

GLOBAL _start
_start:
	mov rsp, 0x7FFFFFFFFFF0

	call main

	.hang:
		jmp .hang
