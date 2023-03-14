%include "rw32-2018.inc"

section .data
    ; zde budou vase data
    x dw 10
    y dw 32
    z dw -33

section .text
_main:
    push ebp
    mov ebp, esp
    
    ; zde bude vas kod
    
    ;deleni kladnych cisel
    mov edx, 0 ;u kladneho deleni je DX a AX jedno cislo - deli se oboje - chces mit na dx 0, aby to nedelalo bordel
    mov ax, [x]
    mov bx, ax
    mov ax, [y]
    div bx
    call WriteInt16
    call WriteNewLine
    mov ax, dx
    call WriteInt16
    

    mov ebx, 0
    mov eax, 0
    call WriteNewLine    
    
    ;deleni zapornych 
    mov ax,[z]
    cwd
    idiv word [y]  
    call WriteInt16
    call WriteNewLine   
    mov ax, dx
    call WriteInt16
    
    pop ebp
    ret