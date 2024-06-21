;Program to input string and reverse it
dosseg
.model small
.stack 100h
.data
v1 db 100 dup(13)
.code
main proc
mov ax,@data
mov ds,ax
mov si,offset v1

L1:                               ;loop for input
mov ah,1
int 21h
cmp al,13
je L2
mov [si],al
inc si
jmp L1

L2:                               ;loop for push
mov si,offset v1
mov cx,100
L3:
mov bx,[si]
push bx
inc si
loop L3

mov cx,100
L4:                               ;loop for pop and print
pop dx
mov ah,2
int 21h
loop L4

mov ah,4ch
int 21h
main endp
end main
