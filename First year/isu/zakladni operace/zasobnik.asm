%include "rw32-2018.inc"

section .data
    ; zde budou vase data
    x dd -75
section .text
_main:
    push ebp
    mov ebp, esp
    
    ; zde bude vas kod
    mov ebx, 100
    ;PUSH src
    ;   ESP -= 4
    ;   [ESP] = src
    push dword 5
    push ebx
    push dword [x]
    call WriteInt16
    call WriteNewLine
    
    ;POP dest
    ;   dest = [ESP]
    ;   ESP += 4    
    
    mov esi, [esp]
    mov eax, esi
    call WriteInt16
    call WriteNewLine

    mov edi, [esp+4]
    mov eax, edi
    call WriteInt16
    call WriteNewLine
    
    add esp, 4
    
    pop eax
    
    call WriteInt16
    call WriteNewLine
    
    pop eax
    
    call WriteInt16
    call WriteNewLine
    

    
    pop ebp
    ret