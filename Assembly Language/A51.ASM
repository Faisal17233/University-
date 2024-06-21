;Program of conditional jump
dosseg
.model small
.stack 100h
.data
v1 db 'number is equal$'
v2 db 'number is not equal$'
.code
main proc
mov ax,@data
mov ds,ax
mov dl,3
mov ah,1
int 21h
sub al,48
cmp al,dl
je L1
mov dx,offset v2
mov ah,9
int 21h
mov ah,4ch
int 21h
L1:
mov dx,offset v1
mov ah,9
int 21h
mov ah,4ch
int 21h
main endp
end main


