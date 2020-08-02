.model small
.stack 100h
.data
	Var1 DW 10
.code    
factorial PROC
	PUSH BP ;Store BP
	PUSH BX ;Store BX

	MOV BP,SP

	MOV BX,[BP+6] ;Ops on BL
	SUB BL,1
	MUL BL  
	
	CMP BL,1
	JE endfact
	PUSH BX
	call factorial
	
	endfact:
		POP BX
		POP BP 
		RET 2
factorial ENDP
			

MAIN proc
	MOV AX,5	
	PUSH AX
	call factorial
	MOV AH,2
	MOV DL,AL
	ADD DL,48
	int 21h
	
	MOV AH,76
	int 21h
END Main