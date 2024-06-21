;Program for taking input using procedure
dosseg
.model small
.stack 100h
.data 
v1 db 50 dup('$')
.code
main proc
mov ax,@data
mov ds,ax
call printt                    ;calling printt procedure

mov dx,offset v1               ;printing
mov ah,9
int 21h

mov ah,4ch
int 21h
main endp

printt proc                    
mov si,offset v1
L1:                            ;loop for taking input
mov ah,1
int 21h
cmp al,13
je L2
mov [si],al
inc si
jmp L1
L2:
ret
printt endp
end main

