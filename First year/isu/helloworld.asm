%include "rw32-2018.inc"

section .data
    ; zde budou vase data
    sMessage db "Hello World!",EOL,0
section .text
_main:
    push ebp
    mov ebp, esp
    mov esi, sMessage
    call WriteString
    
    ; zde bude vas kod

    pop ebp
    ret