.model small
.stack 100h
.data
STRING1 DB 7 DUP(?)
.code
;DATA transfer
MOV AX,@data
MOV ES,AX
MOV DS,AX
LEA DI, STRING1
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
MOV AH,2
LEA SI,STRING1
print:
    LODSB
    MOV DL,AL
    int 21h
    LOOP print    
exit:   
MOV AH,76
INT 21h

    