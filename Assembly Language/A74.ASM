;program for triangle
dosseg
.model small
.stack 100h
.data
v1 db 'triangle$'
v2 db 0
.code
main proc
mov ax,@data
mov ds,ax
L1:
mov ah,6
mov al,1
mov bh,11010000b
mov ch,0
mov cl,0
mov dh,25
mov dl,v2
int 10h
inc v2
cmp v2,9
jne L1

mov dx,offset v1        
mov ah,9
int 21h
mov ah,4ch
int 21h
main endp
end main
