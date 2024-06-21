;Program to input string and print it
dosseg
.model small
.stack 100h
.data
va1 db 50 dup ('$')
va2 db 50 dup ('$')
va3 db 50 dup ('$')
v2 db 'input your name: $'
v3 db 'Name: $'
v4 db 'input your qualification: $'
v5 db 'Qualification: $'
v6 db 'input what you are applying for: $'
v7 db 'Applying for: $'
.code
main proc
mov ax,@data
mov ds,ax

mov dx,offset v2
mov ah,9
int 21h
mov si,offset va1
L1:
mov ah,1
int 21h
cmp al,13
je L2
mov [si],al
inc si
jmp L1

L2:
mov dx,offset v4
mov ah,9
int 21h
mov si,offset va2
L3:
mov ah,1
int 21h
cmp al,13
je L4
mov [si],al
inc si
jmp L3

L4:
mov dx,offset v6
mov ah,9
int 21h
mov si,offset va3
L5:
mov ah,1
int 21h
cmp al,13
je L6
mov [si],al
inc si
jmp L5

L6:
mov dx,offset v3
mov ah,9
int 21h
mov dx,offset va1
mov ah,9
int 21h

mov dx,10
mov ah,2
int 21h

mov dx,13
mov ah,2
int 21h

mov dx,offset v5
mov ah,9
int 21h
mov dx,offset va2
mov ah,9
int 21h

mov dx,10
mov ah,2
int 21h

mov dx,13
mov ah,2
int 21h

mov dx,offset v7
mov ah,9
int 21h
mov dx,offset va3
mov ah,9
int 21h

mov dx,10
mov ah,2
int 21h

mov dx,13
mov ah,2
int 21h

mov ah,4ch
int 21h
main endp
end main
