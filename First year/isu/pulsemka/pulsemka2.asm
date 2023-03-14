%include "rw32-2018.inc"

section .data
    ; zde budou vase data

section .text
_main:
    push ebp
    mov ebp, esp
    
    ; zde bude vas kod
    mov al, 64
    mov bl, 6   
    mov cl, 10
    mul cl
    add ah,bl
    mov dl, 100
    div dl
    pop ebp
    ret