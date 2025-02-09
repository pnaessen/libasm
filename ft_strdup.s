global ft_strdup
extern malloc

ft_strdup:
    push rbp
    mov rbp, rsp
    push rdi            ; save source string pointer
    
    ; First get length of string
    xor rcx, rcx
strlen_loop:
    cmp byte [rdi + rcx], 0
    je malloc_size
    inc rcx
    jmp strlen_loop

malloc_size:
    inc rcx             ; add 1 for null terminator
    push rcx            ; save length
    
    mov rdi, rcx        ; set malloc argument
    call malloc wrt ..plt
    
    pop rcx             ; restore length
    pop rsi             ; restore source string pointer
    
    cmp rax, 0          ; check if malloc failed
    je end_strdup
    
    mov rdi, rax        ; destination = malloc result
    push rax            ; save return value
    
    ; Copy string
copy_strdup:
    mov dl, byte [rsi]
    mov byte [rdi], dl
    inc rsi
    inc rdi
    loop copy_strdup
    
    pop rax             ; restore return value

end_strdup:
    pop rbp
    ret