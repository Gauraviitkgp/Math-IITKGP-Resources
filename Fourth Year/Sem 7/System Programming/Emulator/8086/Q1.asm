print macro A,B
	PUSH AX
	PUSH DX
	MOV AH,9
	IFDEF names
		LEA DX,A
		int 21h
	ENDIF
	IFDEF sachin
		LEA DX,B
		int 21h
	ENDIF
	POP DX
	POP AX
endm
.model small
.stack 100h
.data
names DB "Gaurav$" 
sachin DB "Sachin$"
.code
L1: MOV AX,@data
MOV DS,AX
MOV ES,AX

print names, sachin

MOV AH,76
Int 21h
END