;program for square
dosseg
.model small
.stack 100h
.data
v1 db 'Square$'
.code
main proc
mov ax,@data
mov ds,ax
mov ah,6
mov al,10
mov bh,10110100b
mov ch,0
mov cl,0
mov dh,25
mov dl,25
int 10h
mov dx,offset v1
mov ah,9
int 21h
mov ah,4ch
int 21h
main endp
end main
