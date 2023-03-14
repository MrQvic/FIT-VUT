%include "rw32-2018.inc"

section .data
    ; zde budou vase data
    a dw 20000
    b dd 0
    c dw -20000
    x dw 10
    y dw 320
    z dw -10
section .text
_main:
    push ebp
    mov ebp, esp

    ; zde bude vas kod
    mov eax, 0
    mov edx, 0
    
    ;nasobeni kladnych cisel bez preteceni
    mov ax, [x]
    mov dx, ax
    mov ax, [y]
    mul dx
    call WriteInt16
    
    mov eax, 0
    mov edx, 0
    call WriteNewLine
    
    
    ;nasobeni kladnych cisel s pretecenim
    mov ax, [a]
    mul word [x]
    mov [b], ax
    mov [b+2], dx ;+2 protoze 16b a 32b???
    mov eax, [b]
    call WriteInt32
    
    mov eax, 0
    mov edx, 0
    call WriteNewLine
    
    ;nasobeni kladnych 16b cisel do 32b tak, aby nepretekly
    movzx eax, word[a]
    movzx edx, word[x]
    mul edx
    mov edx, eax
    call WriteInt32
    
    mov eax, 0
    mov edx, 0
    call WriteNewLine
    
    ;nasobeni zapornych cisel
    mov ax, [y]
    mov dx, ax
    mov ax, [z]
    imul ax, dx
    call WriteInt16
    
    mov eax, 0
    mov edx, 0
    call WriteNewLine
    
    ;nasobeni nekladnych 16b cisel do 32b tak, aby nepretekly
    movsx eax, word[c] ;znamenkove rozsireni-rozsiri podle znamenka, tedy zachova i zaporne hodnoty
    movsx edx, word[x] ;-//-
    imul edx
    call WriteInt32
    
    mov eax, 0
    mov edx, 0
    call WriteNewLine
    
    pop ebp
    ret
    
;vycisti:
    ;mov eax, 0
    ;mov edx, 0
    ;call WriteNewLine