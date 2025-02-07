section .text
global ft_strlen

ft_strlen:
    xor rax, rax        ; init compteur= 0

.loop:
    cmp byte [rdi], 0   ; compare with NULL
    je .done            ; if NULL go to .done
    inc rax             ; compteur++
    inc rdi             ; 
    jmp .loop           ; jump to loop

.done:
    ret                 ; return rax
