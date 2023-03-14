%include "rw32-2018.inc"
;
;--- Task 1 ---
;
; Create a function 'task21' to compare elements of two arrays of the 16bit signed values.  
; Pointer to the first array is in the register EAX, pointer to the second array is in the register EBX, 
; and count of the elements of both arrays is in the register ECX.
;
; Function parameters:
;   EAX = pointer to the first array of the 16bit signed values (EAX is always a valid pointer)
;   EBX = pointer to the second array of the 16bit signed values (EBX is always a valid pointer)
;   ECX = count of the elements of the arrays (ECX is an unsigned 32bit value, always greater than 0)
;
; Return values:
;   EAX = 1, if the arrays contain the same values, otherwise EAX = 0
;
; Important:
;   - the function does not have to preserve content of any register
section .data
    
    pole1 dw -1,2,3,4,5
    pole2 dw -1,2,3,4,5
    count dd 5
    
section .text

compare: 
    push ebp
    mov ebp, esp
    
    .for:
        dec ecx 
        movsx edx, word [eax+ecx*2] 
        movsx esi, word [ebx+ecx*2] 
        cmp edx, esi
        jne nope
        jmp .forend
    
    .forend:
        cmp ecx, 0
        je .end
        jmp .for
        
    .end:
        mov eax, 1
        pop ebp
        ret
    
    nope:
        mov eax, 0
        pop ebp
        ret
    
    
    
_main:
    push ebp
    mov ebp, esp
    
    mov eax, pole1
    mov ebx, pole2
    mov ecx, [count]
    
    call compare
    call WriteInt32
    
    pop ebp
    ret