global ft_strcpy

ft_strcpy:
    xor rcx, rcx          

copy_loop:
    mov al, byte [rsi + rcx]  ; get char from source
    mov byte [rdi + rcx], al  ; copy to destination
    cmp al, 0                 ; check if null
    je end_copy              ; if null, end
    inc rcx                  
    jmp copy_loop           

end_copy:
    mov rax, rdi            
    ret