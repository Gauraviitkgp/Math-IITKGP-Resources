TITLE inout: TEST READ_STRING and PRINT_STRING
.model small
.stack
.data
STRING DB 80 DUP(?)
CLRF DB 0Dh,0Ah,'$'
B LABEL WORD 
    DW 5
    DW 7

.code
MAIN PROC
    MOV AX,@data
    MOV DS,AX
    MOV ES,AX

    LEA DI,STRING
    ;CALL READ_STRING
    LEA DX,CLRF
    MOV AH,9
    Int 21h
    
    LEA SI,STRING
    ;CALL PRINT_STRING
    MOV AH,76
    Int 21h
MAIN endp
include READ_STRING.asm
include PRINT_STRING.asm
END MAIN

