EXTERN initialize_lib_kernel
EXTERN main
EXTERN exit
EXTERN environ

GLOBAL _start
_start:
	mov rsp, 0x7FFFFFFFFFF0

	; Save argc, argv, and envp
	mov rax, [rdi]
	push rax
	add rdi, 8
	mov rax, [rdi]
	push rax
	add rdi, 8
	mov rax, [rdi]
	push rax

	; Set environ
	mov rbx, environ
	mov [rbx], rax

	; Initialize standard library
	mov rax, rdi
	add rax, 8
	mov rdi, [rax]
	add rax, 8
	mov rsi, [rax]
	call initialize_lib_kernel

	; Call main
	pop rdx
	pop rsi
	pop rdi
	call main

	mov rdi, rax
	call exit
