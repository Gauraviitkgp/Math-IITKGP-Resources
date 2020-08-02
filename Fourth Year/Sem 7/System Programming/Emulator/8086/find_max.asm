.model small
.stack 100h
.data
	Var1 DW	5,6,35,87,41,22,12
.code    
findmax PROC
	PUSH BP ;Store BP

	MOV BP,SP

	MOV SI,[BP+4] ;Ops on BL
    
	CMP AX,[SI]
	JG nxtpush
	MOV AX,[SI]
	
	nxtpush:
		CMP SI,Var1+12
		JE endmax
        ADD SI,2
        PUSH SI
	
	call findmax
	
	endmax:
		POP BP 
		RET 2
findmax ENDP
			

MAIN proc
	MOV SI,Var1
	XOR AX,AX
	PUSH SI
	call findmax

	
	MOV AH,76
	int 21h
END Main