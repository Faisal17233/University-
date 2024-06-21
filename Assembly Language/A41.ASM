;Program to divide two numbers
dosseg  
.model small
.stack 100h
.data
.code
main proc
mov ax,23
mov bx,6
mov dx,0
div bx
mov cx,ax
add dx,48
mov ah,2
int 21h
mov dx,cx
add dx,48
mov ah,2
int 21h
mov ah,4ch
int 21h
main endp
end main
