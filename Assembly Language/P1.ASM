dosseg
.model small
.stack 100h
.data
v1 db 10 dup('$')
.code
main proc
mov ax,@data
mov ds,ax
mov si,offset v1
mov cx,10
mov bx,36
L1:
mov dx,[si]
cmp dx,36
je L2
mov dx,'a'
mov ah,2
int 21h
inc si
loop L1

L2:
mov dx,'b'
mov ah,2
int 21h
mov ah,4ch
int 21h
main endp
end main
