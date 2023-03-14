%include "rw32-2018.inc"

section .data
    ; zde budou vase data

section .text
_main:
    push ebp
    mov ebp, esp
    
    ; zde bude vas kod
    xor eax,eax
    xor ebx,ebx
    xor ecx,ecx
    xor edx,edx
    mov al, 7
    mov bl, 1
    mov cl, 100
    mul cl
    add ah, bl
    mov dl, 100
    div dl
    inc ax
    add al,ah
    sub al,bl
    cmp al, bl
    jae hop1
    add al, 128
    
    pop ebp
    ret
hop1:
    pop ebp
    ret