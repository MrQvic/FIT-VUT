%include "rw32-2018.inc"

section .data
    ; zde budou vase data
    
section .text
_main:
    push ebp
    mov ebp, esp
    
    xor eax, eax
    mov eax, 10
    jmp cycle
    ret
    
cycle:

    cmp eax, 0
    je end
    call WriteInt8
    call WriteNewLine
    sub eax, 1
    jmp cycle
    ret    
    
end:
    call WriteInt8
    
    
    pop ebp
    ret