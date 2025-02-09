global ft_read
extern __errno_location

ft_read:
    mov rax, 0          ; syscall  for read rdi = fd      rsi = ptr sur le buffer          rdx =  nb d'octets
    syscall
    
    cmp rax, 0
    jl error_read       ; if error (negative return)
    jmp end_read

error_read:
    neg rax             ; get positive error code
    push rax            ; save error code
    call __errno_location wrt ..plt
    pop qword [rax]     ; set errno
    mov rax, -1         ; return -1

end_read:
    ret