EXTERN main

GLOBAL _start
_start:
	call main

	.hang:
		jmp .hang
