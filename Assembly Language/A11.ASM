Dosseg
.model small
.stack 100h
.data
v1 db 0
.code
main proc
mov ax,@data
mov ds,ax
mov cx,1
mov ax,0
l1:
add ax,cx
add cx,2
cmp cx,100
jl l1
mov dx,0
mov bx,10
mov cx,0
l2:
div bx
push dx
mov dx,0
;mov ah,0
inc cx
cmp ax,0
jne l2
mov ah,2
l3:
pop dx
add dx,48
int 21h
loop l3
mov ah,4ch
int 21h
main endp
end main
