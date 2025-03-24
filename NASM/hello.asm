section .data
    message db "Hello, World!", 0xA  ; Message with newline
    len equ $ - message              ; Calculate message length

section .text
    global _start                    ; Entry point for Linux

_start:
    mov rax, 1        ; syscall: write
    mov rdi, 1        ; file descriptor: stdout
    mov rsi, message  ; pointer to message
    mov rdx, len      ; message length
    syscall           ; invoke system call

    ; Exit program
    mov rax, 60       ; syscall: exit
    xor rdi, rdi      ; status: 0 (exit code 0)
    syscall           ; invoke system call
