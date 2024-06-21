;Program to print swap two numbers
Dosseg
.model small
.stack 100h
.data
.code
main proc
mov dx,'5'
push dx
mov bx,'1'
push bx
pop dx
pop bx
mov ah,2
int 21h
mov dx,bx
mov ah,2
int 21h
mov ah,4ch
int 21h
main endp
end main
