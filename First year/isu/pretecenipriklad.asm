%include "rw32-2018.inc"

section .data
    ; zde budou vase data

section .text
_main:
    push ebp
    mov ebp, esp
    
    ; zde bude vas kod
    mov al, 127
    add al, 1
    call WriteInt8
    pop ebp
    ret