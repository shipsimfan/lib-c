SECTION .bss
argc: resq 1
argv: resq 1
envp: resq 1

SECTION .text
EXTERN initialize_standard_library
EXTERN main
EXTERN exit

GLOBAL _start
_start:
	mov rsp, 0x7FFFFFFFFFF0

	; Save argc, argv, envp
	mov rcx, [rdi]
	mov rdx, argc
	mov [rdx], rcx
	add rdi, 8
	mov rcx, [rdi]
	mov rdx, argv
	mov [rdx], rcx
	add rdi, 8
	mov rcx, [rdi]
	mov rdx, envp
	mov [rdx], rcx

	; Initialize standard library
	mov rcx, envp
	mov rdi, [rcx]
	call initialize_standard_library

	; Call main
	mov rcx, argc
	mov rdi, [rcx]
	mov rcx, argv
	mov rsi, [rcx]
	mov rcx, envp
	mov rdx, [rcx]
	call main

	mov rdi, rax
	call exit
