macro galatcode d1
	MOV [ERROR+14],d1
	MOV AH,9
	LEA DX,ERROR
	int 21h
	JMP Exit
endm
macro addkochck d1
	int 21h
	call CASECONVERT
	SCASB
	JNE invalid
	Loop d1
endm 

macro checkend
	int 21h
	CMP AL,']'
	JNE invalid2
endm 


.model small
.stack 100h
.data
ERROR DB 0Dh,0Ah,"ERROR CODE:",?,32d,"PLEASE CORRECT SYNTAX$"
MSG1 DB "Enter the code", 0Dh,0Ah,"$"
AD DB "ADD"
Let1 DB " [ABCDS"
Let2 DB "XI"
Let2A DB "HL"
num  DB "0123456789"
var1 DB "NAME"
var2 DB "GUST"
var3 DB "RANK"
adres DB 2 DUP(?)
size DB 2 DUP(?)
flag1 DB 0
flag2 DB 0
.code
CASECONVERT PROC
	CMP AL,'a'
	JL contin
	CMP AL,'z'
	JG contin
	SUB AL,32
	contin:
	RET
CASECONVERT ENDM

CHECK PROC
	MOV AH,1
	input:
		int 21h
		call CASECONVERT
		;Check first letter is register
		LEA DI, Let1
		MOV CX,7 	 ;6 Different kinds of first letters
		REPNE SCASB 
		JNE chckadd	 ;Check for valid address
		CMP CX,6 	 ;Check Space
		JE input  	 ;If Space take input again
		CMP CX,5     ;Check '['
		JE pointer   ;then its a pointer
		
		;If reached till here means its a valid register or first letter of address
		LEA DI,Let2
		MOV CX,2     ;4 different ttypes of second letters
		int 21h
		call CASECONVERT
		REPNE SCASB
		JE validwordregister              
		MOV CX,2
		LEA DI,Let2A                      
		REPNE SCASB
		JE validbyteregister 
		JMP invalid
		
		chckadd:
			LEA DI,var1
			SCASB
			JNE nxtvar1
			MOV CX,3
			A1:
				addkochck A1
			JMP validadd
				        
			
			nxtvar1:
			LEA DI,var2
			SCASB
			JNE nxtvar2
			MOV CX,3
			A2:
				addkochck A2
			JMP validadd
				
			nxtvar2:
			LEA DI,var3
			SCASB
			JNE number
			MOV CX,3
			A3:
				addkochck A3
			JMP validadd
		
		number:
			CMP flag2,1
			JNE invalid
			MOV CX,10
			LEA DI,num
			REPNE SCASB
			JNE invalid
			
			numinput:
				int 21h
				MOV CX,10
				LEA DI,num
				REPNE SCASB
				JNE validbyteregister
				JMP numinput
			
	pointer:
		CMP flag1,1
		JE invalid2
		
		MOV adres,1
		MOV flag1,1
		JMP input  
	
	validbyteregister:
		CMP flag1,1
		JNE continue3
		checkend
		
		continue3:
		JMP Bahar
				
	validwordregister:
		CMP flag1,1
		JNE continue1
		checkend
		
		continue1:
		MOV SIZE,1
		JMP Bahar
	
	validadd:
		CMP flag1,1
		JNE continue2
		checkend
		
		continue2:
		MOV adres,1
		JMP Bahar
		
	invalid:
		galatcode '2'
	
	invalid2:
		galatcode '3'
	

bahar:
	MOV flag1,0
	RET
CHECK ENDP

MAIN PROC
;initialize
MOV AX,@data
MOV DS,AX
MOV ES,AX

;Ask for input
MOV AH,9
LEA DX,MSG1
int 21h

;Take input
MOV AH,1

;Check if ADD?
LEA DI,AD
MOV CX,3
L1:
	int 21h
	call caseconvert
	SCASB
	JNE galat	
	LOOP L1
	
JMP Checkfirst
;If not
galat:
	galatcode '0' 


;Check First Argument
Checkfirst:
	call check

;Check for comma	
Checkcomma:
	MOV AH,1
	int 21h
	CMP AL,','   

	
	JE Checksecond
	CMP AL,' '
	JE Checkcomma
	galatcode '1'
	
;Check for second input
Checksecond:
	MOV flag2,1 ;Raise flag for 2nd input
	MOV BL,adres
	XCHG adres+1,BL
	MOV adres,BL
	MOV BL,size
	XCHG size+1,BL
	MOV size,BL
	
	call check 

;Check if register register
Checkregreg:
	MOV BL,adres
	MOV BH,adres+1
	ADD BL,BH
	CMP BL,2
	JNE siz
	galatcode '4'
	
	siz:
	MOV BL,size
	MOV BH,size+1
	ADD BL,BH
	CMP BL,1
	JNE Exit
	galatcode '4' 

;Exit
Exit:
MOV AH,76
int 21h
END MAIN
