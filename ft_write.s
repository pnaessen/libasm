global ft_write
extern __errno_location

ft_write:
    mov rax, 1          ; syscall   rdi = fd      rsi = ptr sur le buffer          rdx =  nb d'octets
    syscall
    
    cmp rax, 0
    jl error            ; if error (negative return)
    ret

error:
    neg rax             ; get positive error code
    push rax            ; save error code
    call __errno_location wrt ..plt
    pop qword [rax]     ; set errno
    mov rax, -1         
    ret