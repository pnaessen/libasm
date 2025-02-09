global ft_strcmp

ft_strcmp:
    xor rcx, rcx         

compare_loop:
    movzx rax, byte [rdi + rcx]  ; get char from first string
    movzx rdx, byte [rsi + rcx]  ; get char from second string
    
    cmp rax, rdx
    jne end_compare        ; if different, end
    
    cmp rax, 0             ; check if end of string
    je end_compare         ; if null, end
    
    inc rcx                 
    jmp compare_loop      

end_compare:
    sub rax, rdx           
    ret