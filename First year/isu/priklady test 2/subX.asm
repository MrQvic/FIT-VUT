%include "rw32-2018.inc"
;naprogramuj funkci subX, ktera od jednotlivych prvku pole odecte hodnotu x a ulozi he do daneho mista v poli pB
;dela pole je dana N, predani param. pomoci zasobniku
;vystup eax=0 pokud neni chyba
;vystup eax= -1 pokud pA == 0
;eax = -2 pokud je pB == 0
;fce zachova hodnoty vsech registr mimo eax

;int subX(int *Pa, unsigned int N, int x, int *pB)
;parametry se ukladaji na zasobnik od posledniho k prvnimu - zprava doleva
section .data
    ; zde budou vase data
    pA dd 12,23,42,1,0,52,-1,129
    pB dd 0,0,0,0,0,0,0,0
    N dd 8
    x dd 10
section .text

_main:
    push ebp
    mov ebp, esp
    
    mov eax, [x]
    mov ebx, [N]
    
    push pB
    push eax
    push ebx
    push pA
    
    call subX
    
    add esp, 16
    
    call WriteInt32

    pop ebp
    ret
    

subX:
    push ebp
    mov ebp, esp
    
    push ebx
    push edx
    push ecx
    
    mov ebx, [ebp+8]
    mov edx, [ebp+20]
    mov ecx, [ebp+12]
    
    mov eax, -1
    cmp ebx, 0
    je .error
    
    mov eax, -2
    cmp edx, 0
    je .error
    
    .for:
        dec ecx
        
        mov eax, [ebx + ecx*4]
        sub eax, 10 ;x je ulozeno v ebp+16
        mov [edx + ecx*4], eax
        
        cmp ecx, 0
        je .end
        jmp .for
        
    .end:
        mov eax, 0
        
    .error:
        pop ecx
        pop edx
        pop ebx
        
        pop ebp
        ret
        