;Program for taking input using macro
inputt macro p1
mov si,offset p1
L1:                          ;loop for taking input
mov ah,1
int 21h
cmp al,13
je L2
mov [si],al
inc si
jmp L1
L2:
endm

.model small
.stack 100h
.data
v1 db 50 dup('$')
.code
main proc
mov ax,@data
mov ds,ax
inputt v1                    ;calling macro

mov dx,offset v1             ;printing 
mov ah,9
int 21h

mov ah,4ch
int 21h
main endp
end main
