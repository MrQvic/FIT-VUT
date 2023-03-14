%include "rw32-2018.inc"

section .data
    ; zde budou vase data

section .text

_main:
    push ebp
    mov ebp, esp
    
    mov ebx, 10
    call fakt_reg
    call WriteInt32

    pop ebp
    ret
    
fakt_reg:
    cmp ebx, 1
    jbe fakt_reg_1    
    push ebx
    dec ebx
    call fakt_reg
    pop ebx
    imul ebx
    ret             ;??
    
fakt_reg_1:
    mov eax, 1
    ret