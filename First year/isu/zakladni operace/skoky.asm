%include "rw32-2018.inc"

section .data
    ; zde budou vase data

section .text
_main:
    push ebp
    mov ebp, esp
    
    ;skoky
    ;jz,jnz - jump (nen�) zero(flag)
    ;js,jns - jump (nen�) signflag
    ;jc,jnc - carryflag
    ;jo,jno - overflowflag
    
    ;cmp skoky
    ;ja - jump above (bez znamenka hodnot)
    ;jb - jump bellow (-,,-)
    ;jg - greater (se znamenky hodnoty)
    ;jl - less (se znamenky)
    ;jae - above or equal
    

    pop ebp
    ret