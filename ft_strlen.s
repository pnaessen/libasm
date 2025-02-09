section .text
global ft_strlen

ft_strlen:
    xor rax, rax            ; counter = 0

count_loop:
    cmp byte [rdi + rax], 0 ; check if char is null
    je end                  ; if null, jump to end
    inc rax                 ; increment counter
    jmp count_loop         ; 

end:
    ret
