.model small
.stack 100h
.data
	K1 DB 1,6
	K2 DB 3,7
	K3 DB ?,?
.code
MOV AX,@data
MOV DS,AX
MOV ES,AX

MOV AL,Byte PTR K1[1]
MOV DL,BYTE PTR K2[1]

ADD AL,DL

ADD AL,6
JNA continue
MOV BL,1
AND AL,00001111b

continue:
MOV BYTE PTR K3[1], AL

ADD BL, Byte PTR K1[0]
ADD BL, Byte PTR K2[0]

MOV BYTE PTR K3[0],BL


MOV AH,76
int 21h
END