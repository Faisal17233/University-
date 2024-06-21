
DOSSEG
.MODEL SMALL
.STACK 100H
.DATA
user db ?
.CODE
MAIN PROC
mov ax,@data
mov ds,ax
MOV AH,1           ;TAKING INPUT
INT 21H
MOV user,AL          ;MOVING FROM AL TO user array
SUB user,48          ;SUBTRACT 48 BECAUSE IT IS IN ASCII

MOV AH,4CH
INT 21H
MAIN ENDP
END MAIN
