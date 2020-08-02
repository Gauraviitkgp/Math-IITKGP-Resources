.model small
.stack 100h
.data
	Var1 DW	511
	Var2 DW 510
	Var3 DW ?
.code    
MAIN proc
	MOV AX,@Data
	MOV DS,AX
	MOV ES,AX
	
	MOV SI,VAR1  
	
	MOV AL,BYTE PTR Var1[0]
	MOV DL,BYTE PTR Var2[0]
	ADD AL,DL
	MOV BYTE PTR Var3[0], AL
	     
	MOV AL,BYTE PTR Var1[1]
	MOV DL,BYTE PTR Var2[1]
	ADC AL,DL
	MOV BYTE PTR Var3[1], AL
	
	
	

END Main