section .text
global ft_write
extern __errno_location

ft_write:
    push rbp
    mov rbp, rsp

    mov rax, 1          ;   
    syscall

    cmp rax, 0
    jl .error           ; Si rax < 0, jump if less to .error 

    pop rbp
    ret

.error:
    neg rax             ; Convertir le code d'erreur en positif
    mov rdi, rax
    call __errno_location wrt ..plt
    mov [rax], rdi      ; Stocker le code d'erreur dans errno
    mov rax, -1         ; Retourner -1 en cas d'erreur
    pop rbp
    ret
