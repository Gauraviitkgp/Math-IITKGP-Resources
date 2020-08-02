print_str PROC near
    ;Print the sutff; INPUT SI,CX, OUTPUT print
    PUSH AX
    PUSH SI
    PUSH CX
    PUSH DX
    
    MOV AH,2
    print:
        LODSB
        MOV DL,AL
        int 21h
        Loop print
    
    POP DX
    POP CX
    POP SI
    POP AX
print_str endp