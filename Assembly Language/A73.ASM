;program for Parallelogram
dosseg
.model small
.stack 100h
.data
v1 db 'Parallelogram$'
v2 db 1
v3 db 23
v4 db 21
.code
main proc
mov ax,@data
mov ds,ax

mov ah,6
mov al,1
mov bh,10010111b
mov ch,0
mov cl,0
mov dh,25
mov dl,20
int 10h

L1:
mov ah,6
mov al,1
mov bh,10010111b
mov ch,0
mov cl,v2
mov dh,v3
mov dl,v4
int 10h
inc v2
sub v3,1
inc v4
cmp v2,7
jne L1

mov dx,offset v1
mov ah,9
int 21h
mov ah,4ch
int 21h
main endp
end main
