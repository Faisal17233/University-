;PROGRAM TO PRINT STRINGS
DOSSEG
.MODEL SMALL
.STACK 100H
.DATA
STR1 DB 'I AM$'
STR2 DB 'BATMAN$'
.CODE
MAIN PROC
MOV AX,@DATA
MOV DS,AX

MOV DX,OFFSET STR1            ;ACCESSING STARTING ADDRESS IN MEMORY
MOV AH,9                      ;PRINTING STRING
INT 21H

MOV DX,10                     ;NEXT LINE
MOV AH,2
INT 21H

MOV DX,13                     ;CARRIAGE RETURN
MOV AH,2
INT 21H

MOV DX,OFFSET STR2            ;ACCESSING STARTING ADDRESS IN MEMORY
MOV AH,9                      ;PRINTING STRING
INT 21H

MOV AH,4CH
INT 21H
MAIN ENDP
END MAIN
