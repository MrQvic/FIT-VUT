%include "rw32-2018.inc"
;Naprogramuj fci getMAX, ktera v poli 32bit cisel se znamenkem najde nejvetsi cislo, je tøeba zachovat hodnoty registru
section .data
    ; zde budou vase data
    pole dd 15,63,-5,18,129,1234,0,12345
section .text
getMAX:
    push ebp
    mov ebp, esp
    
    push ecx ; je potøeba zachovat hodnoty reg
    push esi ; je potøeba zachovat hodnoty reg
    
    mov esi, [ebp+12] ;ukazatel na pole
    mov ecx, [ebp+8]  ;ukazatel na pocet hodnot v poli
    
    mov eax, -999999
    
    .for:
        dec ecx
        cmp eax, [esi+ecx*4] ;jedu od konce
        jg .forend ;jl, pokud chceme minimum
        mov eax, [esi+ecx*4]
        
    .forend:
        cmp ecx, 0
        je .end
        jmp .for
        
    .end:
        pop esi ; je potøeba zachovat hodnoty reg
        pop ecx ; je potøeba zachovat hodnoty reg
    
    pop ebp
    ret 8
    
_main:
    push ebp
    mov ebp, esp
    
    mov esi, pole
    mov ecx, 8
    
    push esi
    push ecx
    call getMAX
    call WriteInt16
    
    pop ebp
    ret