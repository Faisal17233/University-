;Program to print array using loop
dosseg
.model small
.stack 100h
.data
v1 db '1','2','3','4','5'
.code
main proc
mov ax,@data
mov ds,ax
mov si,offset v1
mov cx,5
L1:
mov dx,[si]
mov ah,2
int 21h
inc si
loop L1
mov ah,4ch
int 21h
main endp
end main
