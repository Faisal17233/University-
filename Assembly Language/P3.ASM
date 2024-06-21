Dosseg
.model small
.stack 100h
.data
.code
main proc
mov ax,87
AAM
mov bh,ah
mov bl,al
add bh,48
mov dl,bh
mov ah,2
int 21h
mov dl,bl
add dl,48
mov ah,2
int 21h

mov ah,4ch
int 21h
main endp
end main
