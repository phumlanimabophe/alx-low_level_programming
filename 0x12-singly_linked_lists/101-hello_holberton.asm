section .data
    message db "Hello, Holberton", 10, 0
    format db "%s", 0
    
section .text
    global main
    
main:
    push rbp
    mov rbp, rsp
    
    ; Set up the argument to printf
    mov rdi, format
    mov rsi, message
    xor rax, rax
    
    ; Call printf
    call printf
    
    ; Clean up the stack
    add rsp, 8
    
    ; Return 0
    xor eax, eax
    pop rbp
    ret
