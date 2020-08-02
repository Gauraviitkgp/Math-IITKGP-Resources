.model small
.8087
.data
K DB 10 DUP(0)
.stack 100h

.code
MOV CX,0
XOR DX,DX ;We would be pushing DX
LEA BX,K

;Read the sign bit
MOV AH,2
int 21h

MOV [BX],0;Defalt value
CMP AL,'-'
JNE read
MOV [BX],128

;Next Reading
read:
	CMP AL,0Dh
	JE store
	SUB AL,48
	PUSH DX
	INC CX
	int 21h
	JMP read
MOV BX,BX+10
;Packing as BCD	
store:
	MOV CL,4
	POP DX
	MOV AL,DL
	POP DX
	SHL DL,4
	OR DL,AL
	OR BX,DL
	DEC BX
	DEC CX
	Loop store

END
	
	
	
	
	
	
	
	
	