READ_STR PROC NEAR
;Read string on the variable addressed by SI
;Input: DI, output DI,BX(size)
PUSH AX
PUSH DI
MOV AH,1
XOR CX,CX

input:
    int 21h
    CMP AL,0Dh
    JE bahar
    CMP AL,8h
    JNE store
    DEC CX
    DEC DI
    JMP input
    store:
        STOSB
        INC CX
        JMP input
    
bahar:
POP DI
POP AX
READ_STR ENDP  