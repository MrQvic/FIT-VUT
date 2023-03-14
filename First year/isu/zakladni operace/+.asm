%include "rw32-2018.inc"

section .data
    ; zde budou vase data

section .text
_main:
    push ebp
    mov ebp, esp
    call ReadInt16
    call WriteInt16
    mov dx, ax
    call WriteNewLine
    call ReadInt16
    call WriteInt16
    call WriteNewLine
    add ax, dx
    call WriteInt16
    ; zde bude vas kod

    pop ebp
    ret