;Bonus Program 
dosseg
.model small
.stack 100h
.data
.code
main proc
mov ah,6
mov al,40
mov bh,11110000b
mov ch,0
mov cl,0
mov dx,184fh
int 10h

mov ah,6
mov al,1
mov bh,10010000b
mov ch,0
mov cl,20
mov dh,17
mov dl,53
int 10h

mov ah,6
mov al,1
mov bh,10100000b
mov ch,0
mov cl,20
mov dh,16
mov dl,53
int 10h

mov ah,6
mov al,1
mov bh,11010000b
mov ch,0
mov cl,20
mov dh,15
mov dl,53
int 10h

mov ah,6
mov al,1
mov bh,11000000b
mov ch,0
mov cl,20
mov dh,14
mov dl,53
int 10h

mov ah,6
mov al,1
mov bh,10110000b
mov ch,0
mov cl,20
mov dh,13
mov dl,53
int 10h

mov ah,6
mov al,1
mov bh,11100000b
mov ch,0
mov cl,20
mov dh,12
mov dl,53
int 10h

mov ah,6
mov al,1
mov bh,10010000b
mov ch,0
mov cl,20
mov dh,11
mov dl,53
int 10h

mov ah,6
mov al,1
mov bh,11010000b
mov ch,0
mov cl,20
mov dh,10
mov dl,53
int 10h

mov ah,6
mov al,1
mov bh,11000000b
mov ch,0
mov cl,20
mov dh,9
mov dl,53
int 10h

mov ah,4ch
int 21h
main endp
end main
