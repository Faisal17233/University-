;program for triangle
dosseg
.model small
.stack 100h
.data
v1 db 'triangle$'
v2 db 1
.code
main proc
mov ax,@data
mov ds,ax
L1:
mov dl,v2
mov ah,2
int 21h
inc v2
cmp v2,3
jne L1
mov ah,4ch
int 21h
main endp
end main
