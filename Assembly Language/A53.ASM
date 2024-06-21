;Program of multiplication & conditional jump
dosseg
.model small
.stack 100h
.data
.code
main proc
mov ah,1
int 21h
mov cl,al
sub cl,48
mov ah,1
int 21h
sub al,48
mul cl
mov bx,9
cmp ax,bx
jg L1
mov dx,ax
add dx,48
mov ah,2
int 21h
mov ah,4ch
int 21h

L1:
AAM
mov cl,al
add cl,48
mov dl,ah
add dl,48
mov ah,2
int 21h
mov dl,cl
mov ah,2
int 21h
mov ah,4ch
int 21h
main endp
end main
