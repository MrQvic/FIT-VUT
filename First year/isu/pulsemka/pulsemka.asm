%include "rw32-2018.inc"

section .data
    ; zde budou vase data

section .text
_main:
    push ebp
    mov ebp, esp
    
    ; zde bude vas kod
MOV AL, 8     ;al = 8
MOV BL, 17   ;bl = 17
MOV CL, AL   ;cl = 8
ADD CL, 2    ; cl = 10
TEST CL, 7   ; cl -> 1010 & 0111 -> 0010 =/ 0
JNZ hop1     ; plati
XOR CL, 255  ; skip

hop1:        ;
MOV AH, CL   ; ah = 10
AND CL, 7    ; cl = 0010 = 2
SAR AX, CL   ; posuò o cl (2) doprava -> 00001010|00001000 -> 00000010|10000010
XCHG AL, DL  ; al = hovno, dl = al = 10000010
AND DL, 127  ; 01111111 & 10000010 -> 00000010 = 2
;ØEŠENÍ:         ; 2
pop ebp
ret