.model SMALL
PUBLIC Convert
.stack 100h
.data
.code
CONVERT PROC near
;Input SI=Source CX=size
PUSH DI
PUSH AX
MOV DI,SI
L1:
	LODSB
	INC CX
	CMP AL,'a'
	JL nxt
	CMP AL,'z'
	JG nxt
	SUB AL,'a'-'A'
	nxt:
		STOSB
		INC CX
		LOOP L1
	
	
POP DI
POP AX	
RET
CONVERT ENDP
END