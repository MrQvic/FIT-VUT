%include "rw32-2018.inc"

section .data
    ; zde budou vase data
    x dw -50
    y dw 7
    z dw 0
    
    a dw 20
section .text
_main:
    push ebp
    mov ebp, esp
    
    ; z = (x*y + y*y -50)/20
    
    ;x*y
    mov ax, [x]
    imul word [y]
    mov bx, ax
    ;call WriteInt16
    
    ;y*y
    mov ax, [y]
    mul word [y]
    
    ;call WriteNewLine
    ;call WriteInt16
    
    ;x*y+y*y
    add bx, ax
    mov ax, bx
    
    ;call WriteNewLine
    ;call WriteInt16
    
    ;x*y+y*y-50
    sub ax, 50
    
    ;call WriteNewLine
    ;call WriteInt16
    
    ;(x*y+y*y-50)/20
    cwd
    idiv word [a]
    
    ;call WriteNewLine
    call WriteInt16
    
    ;vyjadreni zbytku
    mov ax, dx
    
    call WriteNewLine
    call WriteInt16
    
    pop ebp
    ret