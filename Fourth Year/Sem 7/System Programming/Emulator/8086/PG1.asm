.model SMALL
EXTRN CONVERT:PROC
.stack 100h
.data
Naam DB 6 DUP(?),'$'
.code
MAIN PROC
MOV AX,@data
MOV DS,AX
MOV ES,AX

MOV AH,1
LEA DI,Naam
rept 6
	int 21h
	STOSB
endm

LEA SI,Naam
MOV CX,6
call Convert


MOV AH,9
LEA DX,naam
int 21h


MOV AH,76
int 21h
MAIN ENDP
END MAIN