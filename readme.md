# Guide de référence Assembly x86_64 (Intel syntax)

## Registres principaux (64 bits)
- `rax` : Accumulateur, utilisé pour les valeurs de retour
- `rbx` : Base register (préservé)
- `rcx` : Counter register, utilisé pour les boucles
- `rdx` : Data register, 3ème argument
- `rsi` : Source Index, 2ème argument
- `rdi` : Destination Index, 1er argument
- `rbp` : Base Pointer (pointeur de base de la stack)
- `rsp` : Stack Pointer (pointeur du sommet de la stack)
- `r8` à `r15` : Registres supplémentaires

## Versions des registres
- Registre 64 bits : `rax`
- Registre 32 bits : `eax`
- Registre 16 bits : `ax`
- Registre 8 bits : `al` (low byte) et `ah` (high byte)

## Instructions de base

### Manipulation de données
- `mov dest, src` : Copie src dans dest
  ```nasm
  mov rax, 42      ; met 42 dans rax
  mov rax, rbx     ; copie rbx dans rax
  ```

- `push reg/value` : Pousse sur la stack
  ```nasm
  push rax         ; sauvegarde rax sur la stack
  push 42          ; pousse 42 sur la stack
  ```

- `pop reg` : Récupère de la stack
  ```nasm
  pop rax          ; récupère la valeur du sommet de la stack dans rax
  ```

### Opérations arithmétiques
- `add dest, src` : Addition
- `sub dest, src` : Soustraction
- `inc reg` : Incrémente
- `dec reg` : Décrémente
- `neg reg` : Change le signe
- `mul reg` : Multiplication non signée
- `div reg` : Division non signée

### Opérations logiques
- `and dest, src` : ET logique
- `or dest, src` : OU logique
- `xor dest, src` : OU exclusif
  ```nasm
  xor rax, rax     ; Met rax à 0 (plus rapide que mov rax, 0)
  ```

### Instructions de comparaison
- `cmp a, b` : Compare a et b
- `test a, b` : Test bits (AND logique sans sauvegarder le résultat)

### Sauts conditionnels
- `je/jz` : Saut si égal / zéro
- `jne/jnz` : Saut si non égal / non zéro
- `jl` : Saut si inférieur (signé)
- `jle` : Saut si inférieur ou égal
- `jg` : Saut si supérieur (signé)
- `jge` : Saut si supérieur ou égal
- `jmp` : Saut inconditionnel

## Sections d'un programme

```nasm
section .data       ; données initialisées
    msg db "Hello", 0

section .bss        ; données non initialisées
    buffer resb 64  ; réserve 64 bytes

section .text       ; code
global main        ; point d'entrée
```

## Convention d'appel System V AMD64
1. Arguments passés dans l'ordre : `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`
2. Valeur de retour dans `rax`
3. Registres à préserver : `rbx`, `rbp`, `r12-r15`
4. Registres volatiles : `rax`, `rdi`, `rsi`, `rdx`, `rcx`, `r8-r11`

## Syscalls Linux x86_64
- Numéro de syscall dans `rax`
- Arguments dans `rdi`, `rsi`, `rdx`, `r10`, `r8`, `r9`
- Syscalls communs :
  - write (1)
  - read (0)
  - exit (60)

## Exemple d'utilisation de la stack

```nasm
function:
    push rbp           ; sauvegarde l'ancien base pointer
    mov rbp, rsp       ; établit un nouveau stack frame
    
    ; code de la fonction
    
    mov rsp, rbp       ; restaure le stack pointer
    pop rbp            ; restaure l'ancien base pointer
    ret                ; retourne à l'appelant
```

## Gestion des chaînes
- Accès à un caractère : `[reg + offset]`
  ```nasm
  mov al, [rdi]       ; charge un caractère depuis rdi
  mov [rdi], al       ; stocke un caractère à l'adresse rdi
  ```

## Astuces courantes
1. Mettre un registre à zéro :
   ```nasm
   xor rax, rax       ; plus efficace que mov rax, 0
   ```

2. Comparer avec zéro :
   ```nasm
   test rax, rax      ; plus efficace que cmp rax, 0
   ```

3. Incrémenter/Décrémenter :
   ```nasm
   inc rax            ; plus court que add rax, 1
   dec rax            ; plus court que sub rax, 1
   ```