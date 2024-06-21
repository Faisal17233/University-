dosseg
print macro p1       ;create macro p1 for directly print strings
mov dx,offset p1
mov ah,9
int 21h
endm
printresult macro p2
mov dl,p2           ;create macro p2 for directly print single char or number
mov ah,2
int 21h
endm
.model small
.stack 100h
.data
str00 db 'RECTANGULAR$'
str01 db 'SQUARE$'
str02 db 'PARALLELOGRAM$'
str03 db 'TRIANGLE  $'
str04 db 'RIGHTANGLE $'
str05 db 'DIAMOND $'
str06 db 'OCTAGON$'
str07 db 'TRAPEZOID$'
str1 db '                                IDENTIFY THE SHAPE$'
str2 db '                                      OPTIONS$    '
str3 db '                           1=TRIANGLE         2=SQUARE$'
str4 db '                           3=PARALLELOGRAM   4=RECTANGULAR$'
str3t3 db  '                           1=DIAMOND          2=RIGHTANGLE TRIANGLE$'
str4t4 db  '                           3=OCTAGON          4=TRAPEZOID$'
str5 db '                           You guess the correct shape$'
str6 db '                           You guess the wrong shape$'
str7 db '                      Enter the shape of above diagram: $'
str8 db '                        PRESS ENTER FOR REACH TO NEXT PAGE $'
STR9 DB '     SCORE BOARD$'
ss1 db 'Correct Answer:$'
ss2 db 'Wrong Answer:$'
s1 db 0                   ;for store correct point in game
s12 db 0                  ;for store wrong point in game
s11 db  ' Your total points is : $'
v1 db 0
str11 db 3        ;for parallelogram       ;using this value for making shape
str22 db 25       ;for parallelogram       ;
str33 db 3        ;for parallelogram       ; 
str44 db 55       ;for parallelogram       ;
str111 db 2       ;for triangle            ;
str222 db 38      ;for triangle            ;
str333 db 2       ;for triangle            ;
str444 db 38      ;for triangle            ;
str1111 db 2      ;for rigthangle triangle ;
str2222 db 36     ;for rigthangle triangle ;
str3333 db 2      ;for rigthangle triangle ;
str4444 db 36     ;for rigthangle triangle ;
strt1 db 2        ;for diamond             ;
strt2 db 38       ;for diamond             ;
strt3 db 2        ;for diamond             ;
strt4 db 38       ;for diamond             ;
strt5 db 2        ;for octagon             ;
strt6 db 36       ;for octagon             ;
strt7 db 2        ;for octagon             ;
strt8 db 44       ;for octagon             ;
strt11 db 2       ;for trapezoid           ;
strt22 db 34      ;for trapezoid           ;
strt33 db 2       ;for trapezoid           ;
strt44 db 46      ;for trapezoid           ;using this value for making shape
game db 'WELCOME TO THE SHAPE IDENTIFY GAME$' 
game1 db 'MULTIPLE PLAYER GAME$'
game3 db 'MINIMUM PLAYERS = 1$'
game4 db 'MAXIMUM PLAYERS = 4$'
game5 db 'ENTER HOW MANY PLAYERS WANT TO $'
GAME6 DB 'PLAY THIS GAME = $'
player db 'Enter Player Name = $'
player1 db 20 dup('$')     ;use array for input player name
player2 db 20 dup('$')     ;use array for input player name
player3 db 20 dup('$')     ;use array for input player name
player4 db 20 dup('$')     ;use array for input player name
result1 db 0               ;for store the result of player
result2 db 0               ;for store the result of player
result3 db 0               ;for store the result of player
result4 db 0               ;for store the result of player
shotcut db 0               ;in this we move no of player  ;input by user
wins db ' WIN THE GAME$'
.code                                      
main proc
mov ax,@data
mov ds,ax
call gamemainlogic  ;calling the define funtion in which we can create
g1:                 ;background and print some string 
g2:
mov ah,1            ;take input from user
int 21h
mov shotcut,al      ;mov user input value in shotcut(variable)
cmp shotcut,49      ;compare shotcut with 1 if less than 1 then input again 
jl g1
cmp shotcut,52      ;compare shotcut with 4 if grater than 1 then input again
jg g2

MOV AH,1            ;FOR WAIT TO REACH THE NEXT PAGE
INT 21H

cmp shotcut,49   ;cmp if input is 1 then jump to shot1 for run game one time 
je shotcut1
jmp shot2
shotcut1:
jmp shot1
shot2:
cmp shotcut,50   ;cmp if input is 2 then jump to shot3 for run game two time
je shotcut2
jmp shot4
shotcut2:
jmp shot3
shot4:

cmp shotcut,51  ;cmp if input is 3 then jump to shotcut3 for run game 3 time
je shotcut3
cmp shotcut,52  ;cmp if input is 4 then jump to shotcut4 for run game 4 time
je shotcut4
shotcut4:     ;if user give input 4 players then program will start here

call gamelogic          ;calling the define funtion in which we can create
                        ;background and print some string 
mov si,offset player1          
p1:                   ;this code is take input player name from user
mov ah,1              ;and store in player1(variable)
int 21h               
cmp al,13
je outside
mov [si],al
inc si
jmp p1
outside:          ;after taking input name run the rest of the program

call rectuangle      ;call function where we define this shape and print 
call square          ;many string and many funtion define further in the
call parallogram     ;all shape define funtion
call triangle
call rigthangletriangle
call diamond
call octagon
call triod
mov cl,s12    ;in s12 wrong point this value move in cl
sub s1,cl     ;in s1 correct point subtract the wrong point from correct point because of nagative marking
add s1,48     ;add 48 in s1 because assembly need ascii value
cmp s1,48     ;compare correct point with 0 
jl zero       ;if point is less than 0 jump to zero and mov 0 in result of player
mov cl,s1     ;mov the correct point in cl
mov result1,cl   ;mov the correct point in result1(variable)
jmp zeroout     
zero:
mov result1,48
zeroout:

shotcut3:     ;if user give input 3 players then program will start here
call gamelogic          ;calling the define funtion in which we can create
                        ;background and print some string 
mov si,offset player2         
p2:                   ;this code is take input player name from user
mov ah,1              ;and store in player2(variable)
int 21h
cmp al,13
je outside2
mov [si],al
inc si
jmp p2
outside2:            ;after taking input name run the rest of the program

call rectuangle      ;call function where we define this shape and print 
call triangle          ;many string and many funtion define further in the
call octagon         ;all shape define funtion
call square
call rigthangletriangle
call diamond                  
call parallogram               
call triod
mov cl,s12    ;in s12 wrong point this value move in cl
sub s1,cl     ;in s1 correct point subtract the wrong point from correct point because of nagative marking
add s1,48     ;add 48 in s1 because assembly need ascii value
cmp s1,48     ;compare correct point with 0 
jl zero2       ;if point is less than 0 jump to zero and mov 0 in result of player
mov cl,s1     ;mov the correct point in cl
mov result2,cl   ;mov the correct point in result2(variable)
jmp zeroout2
zero2:
mov result2,48
zeroout2:

shot3:      ;if user give input 2 players then program will start here
call gamelogic          ;calling the define funtion in which we can create
                        ;background and print some string 
mov si,offset player3         
p3:                   ;this code is take input player name from user
mov ah,1              ;and store in player3(variable)
int 21h
cmp al,13
je outside3
mov [si],al
inc si
jmp p3
outside3:            ;after taking input name run the rest of the program

call rectuangle      ;call function where we define this shape and print 
call diamond         ;many string and many funtion define further in the
call parallogram     ;all shape define funtion
call triangle
call triod         
call square                     
call octagon
call rigthangletriangle
mov cl,s12    ;in s12 wrong point this value move in cl
sub s1,cl     ;in s1 correct point subtract the wrong point from correct point because of nagative marking
add s1,48     ;add 48 in s1 because assembly need ascii value
cmp s1,48     ;compare correct point with 0 
jl zero3       ;if point is less than 0 jump to zero and mov 0 in result of player
mov cl,s1     ;mov the correct point in cl
mov result3,cl   ;mov the correct point in result3(variable)
jmp zeroout3
zero3:
mov result3,48
zeroout3:
shot1:        ;if user give input 1 players then program will start here
call gamelogic          ;calling the define funtion in which we can create
                        ;background and print some string 
mov si,offset player4         
p4:                   ;this code is take input player name from user
mov ah,1              ;and store in player4(variable)
int 21h
cmp al,13
je outside4
mov [si],al
inc si
jmp p4
outside4:            ;after taking input name run the rest of the program

call rectuangle      ;call function where we define this shape and print 
call triod           ;many string and many funtion define further in the
call rigthangletriangle    ;all shape define funtion
call octagon
call parallogram    
call diamond                    
call triangle
call square
mov cl,s12    ;in s12 wrong point this value move in cl
sub s1,cl     ;in s1 correct point subtract the wrong point from correct point because of nagative marking
add s1,48     ;add 48 in s1 because assembly need ascii value
cmp s1,48     ;compare correct point with 0 
jl zero4       ;if point is less than 0 jump to zero and mov 0 in result of player
mov cl,s1     ;mov the correct point in cl
mov result4,cl   ;mov the correct point in result4(variable)
jmp zeroout4
zero4:
mov result4,48
zeroout4:
;for score board
CALL COLOR         ;call funtion that print backgrond page
MOV AH,7             ;for create sroceboard page
MOV AL,0             ;
MOV BH,11101100B     ;
MOV CH,8             ;
MOV CL,20            ;
MOV DH,18            ;
MOV DL,60            ;
INT 10H              ;
MOV AH,7             ;
MOV AL,0             ;
MOV BH,10101110B     ;
MOV CH,9             ;
MOV CL,22            ;
MOV DH,17            ;
MOV DL,58            ;
INT 10H              ;for create sroceboard page

MOV AH,7         ;for print grapic at the backside of sroceboard string
MOV AL,0
MOV BH,10000010B    ;black color with green text with blinking
MOV CH,10
MOV CL,35
MOV DH,10
MOV DL,45
INT 10H

MOV AH,2      ;move curse position accroding to we wants
MOV BH,0
MOV DH,10
MOV DL,30
INT 10H
PRINT STR9    ;print str9 at the position we set above

cmp shotcut,49  ;cmp input inwhich store no of player if input 1 then jmp
je shotcut5     ;to shotcut5 inwhich we make sorceboard a/c to 1 player

cmp shotcut,50  ;cmp input inwhich store no of player if input 2 then jmp
je shotcut6     ;to shotcut6 inwhich we make sorceboard a/c to 2 player

cmp shotcut,51  ;cmp input inwhich store no of player if input 3 then jmp
je shotcut7     ;to shotcut7 inwhich we make sorceboard a/c to 3 player

cmp shotcut,52  ;cmp input inwhich store no of player if input 4 then jmp
je shotcut8     ;to shotcut8 inwhich we make sorceboard a/c to 4 player

shotcut8:       ;for sorce board starting here if player is 4
MOV AH,2        ;set the position of cusre a/c to our need
MOV BH,0
MOV DH,12
MOV DL,25
INT 10H
print player1         ;print player1 name at the position we set
print s11             ;print s11(string in variables) at the position we set
printresult result1   ;print result of the player

shotcut7:     ;for sorce board starting here if player is 3
MOV AH,2      ;set the position of cusre a/c to our need
MOV BH,0
MOV DH,13
MOV DL,25
INT 10H
print player2          ;print player2 name at the position we set
print s11              ;print s11(string in variables) at the position we set
printresult result2    ;print result of the player

shotcut6:      ;for sorce board starting here if player is 2
MOV AH,2       ;set the position of cusre a/c to our need
MOV BH,0
MOV DH,14
MOV DL,25
INT 10H
print player3         ;print player3 name at the position we set
print s11             ;print s11(string in variables) at the position we set
printresult result3   ;print result of the player

shotcut5:      ;for sorce board starting here if player is 1
MOV AH,2       ;set the position of cusre a/c to our need
MOV BH,0
MOV DH,15
MOV DL,25
INT 10H
print player4          ;print player4 name at the position we set
print s11              ;print s11(string in variables) at the position we set
printresult result4    ;print result of the player

mov cl,result3
cmp result4,cl     ;CMP PLAYER4 SCORE GRATER THAN PLAYER3
jg win1
jmp lose1
win1:
mov cl,result2
cmp result4,cl     ;CMP PLAYER4 SCORE GRATER THAN PLAYER2
jg win2
jmp lose2
win2:
mov cl,result1
cmp result4,cl      ;CMP PLAYER4 SCORE GRATER THAN PLAYER1
jg win3
jmp lose3
win3:
MOV AH,2       ;set the position of cusre a/c to our need
MOV BH,0
MOV DH,16
MOV DL,30
INT 10H
print player4     ;if PLAYER4 SCORE GRATER THAN all PLAYERs than print name of player4
print wins
lose3:
lose2:
lose1:



mov cl,result4
cmp result3,cl        ;CMP PLAYER3 SCORE GRATER THAN PLAYER4
jg win4
jmp lose4
win4:
mov cl,result2
cmp result3,cl        ;CMP PLAYER3 SCORE GRATER THAN PLAYER2
jg win5
jmp lose5
win5:
mov cl,result1
cmp result3,cl       ;CMP PLAYER3 SCORE GRATER THAN PLAYER1
jg win6
jmp lose6
win6:
MOV AH,2       ;set the position of cusre a/c to our need
MOV BH,0
MOV DH,16
MOV DL,30
INT 10H
print player3   ;if player3 score grater than all players than print name of player3
print wins
lose4:
lose5:
lose6:

mov cl,result4
cmp result2,cl   ;CMP PLAYER2 SCORE GRATER THAN PLAYER4
jg win7
jmp lose7
win7:
mov cl,result3
cmp result2,cl     ;CMP PLAYER2 SCORE GRATER THAN PLAYER3
jg win8
jmp lose8
win8:
mov cl,result1
cmp result2,cl    ;CMP PLAYER2 SCORE GRATER THAN PLAYER1
jg win9
jmp lose9
win9:
MOV AH,2       ;set the position of cusre a/c to our need
MOV BH,0
MOV DH,16
MOV DL,30
INT 10H
print player2   ;if PLAYER2 SCORE GRATER THAN all PLAYERs than print name of player2
print wins
lose7:
lose8:
lose9:


mov cl,result4
cmp result1,cl     ;CMP PLAYER1 SCORE GRATER THAN PLAYER4
jg win10
jmp lose10
win10:
mov cl,result3
cmp result1,cl    ;CMP PLAYER1 SCORE GRATER THAN PLAYER3
jg win11
jmp lose11
win11:
mov cl,result2
cmp result1,cl    ;CMP PLAYER1 SCORE GRATER THAN PLAYER2
jg win12
jmp lose12
win12:
MOV AH,2       ;set the position of cusre a/c to our need
MOV BH,0
MOV DH,16
MOV DL,30
INT 10H
print player1     ;if PLAYER1 SCORE GRATER THAN all PLAYERs than print name of player1
print wins
lose10:
lose11:
lose12:

mov ah,4ch       ;here our program end           
int 21h

main endp
COLOR PROC
mov ah,6          ;in this funtion we define the background page
mov al,0
mov bh,00010100b
mov ch,0
mov cl,0
mov dh,80
mov dl,80
int 10h

mov ah,6
mov al,0
mov bh,01110001b
mov ch,1
mov cl,2
mov dh,23
mov dl,77
int 10h
RET
COLOR ENDP
work1 proc         ;in this we can print strings on the background page
MOV AH,7           ;this for grahpic at the background of
MOV AL,0           ;guess the shape (string)
MOV BH,00000010B
MOV CH,14
MOV CL,32
MOV DH,14
MOV DL,49
INT 10H
MOV AH,7            ;this for grahpic at the background of
MOV AL,0            ;option (string)
MOV BH,00000010B
MOV CH,15
MOV CL,38                  ;;;;;;;;;;;;;;;;;;;;;;
MOV DH,15
MOV DL,44
INT 10H

mov ah,2      ;for set curse as we want
mov bh,0
mov dh,12
mov dl,19
int 10h
call enter        ;call enter funtion in which we print nextline
call enter       
print str1        ;print strings with the help of macro
call enter
print str2
call enter
print str3         ;print option 1 , 2
call enter
print str4         ;print option 3 , 4
call enter
print str7
ret
work1 endp

work2 proc        ;in this we can strings on the background page
MOV AH,7           ;this for grahpic at the background of
MOV AL,0           ;guess the shape (string)
MOV BH,00000010B
MOV CH,14
MOV CL,32
MOV DH,14
MOV DL,49
INT 10H
MOV AH,7            ;this for grahpic at the background of
MOV AL,0            ;option (string)
MOV BH,00000010B
MOV CH,15
MOV CL,38
MOV DH,15
MOV DL,44
INT 10H

mov ah,2               ;for set curse as we want
mov bh,0
mov dh,12         ;this method is same as above method except option
mov dl,19         ;in this we can change the option string
int 10h
call enter
call enter          
print str1          ;print strings with the help of macro
call enter          ;call enter funtion in which we print nextline
print str2
call enter
print str3t3       ;option 1 , 2 
call enter
print str4t4       ;option 3 , 4
call enter
print str7
ret
work2 endp

work3 proc    ;in this funtion we make correct point and worng point
MOV AH,7              
MOV AL,0         ;here we can print grahpic at the backside of point
MOV BH,00011101B
MOV CH,4
MOV CL,61
MOV DH,5
MOV DL,76
INT 10H

MOV AH,2     ;set curse at above rigth corner
MOV BH,0
MOV DH,4
MOV DL,61
INT 10H
print ss1    ;print ss1 inwhich string of correct point
mov dl,s1    ;print s1 in s1 we store correct point
mov ah,2
int 21h
MOV AH,2        ;set curse at above rigth corner
MOV BH,0
MOV DH,5
MOV DL,61
INT 10H
print ss2    ;print ss1 inwhich string of worng point
mov dl,s12   ;print s12 in s12 we store worng point
mov ah,2
int 21h
                   ;;;;
ret
work3 endp
gamelogic proc  ;in this funtion we make a welcome page that input 
                ;player name
call color     ;call color inwhich we make background page
MOV AH,7             ;for grahpic at the backside of players input
MOV AL,0             ;
MOV BH,11101100B     ;
MOV CH,8             ;
MOV CL,20            ;
MOV DH,18            ;
MOV DL,60            ;
INT 10H              ;
MOV AH,7             ; 
MOV AL,0             ; 
MOV BH,10101110B     ; 
MOV CH,9             ;
MOV CL,22            ;
MOV DH,17            ;
MOV DL,58            ;
INT 10H              ;for grahpic at the backside of players input

MOV AH,2        ;set curse at the middle of the page
MOV BH,0
MOV DH,11
MOV DL,23
INT 10H
PRINT game      ;print strings at the position we set above

MOV AH,2          ;set curse at the middle of the page
MOV BH,0
MOV DH,12
MOV DL,33
INT 10H
PRINT game1     ;print strings at the position we set above

MOV AH,2         ;set curse at the middle of the page
MOV BH,0
MOV DH,14
MOV DL,26
INT 10H
print player   ;print strings at the position we set above

ret
gamelogic endp
gamemainlogic proc;in this funtion we make a page that input enter your players
                   ;this is the first page of our program
call color            ;call color inwhich we make background page

MOV AH,7             ;for grahpic at the backside of players input
MOV AL,0             ;
MOV BH,00101100B     ;
MOV CH,8             ;
MOV CL,20            ;
MOV DH,18            ;
MOV DL,60            ;
INT 10H              ;
MOV AH,7             ;
MOV AL,0             ;
MOV BH,00000010B     ;
MOV CH,9             ;
MOV CL,22            ;
MOV DH,17            ;
MOV DL,58            ;
INT 10H              ;for grahpic at the backside of players input

MOV AH,2        ;set curse at the middle of the page
MOV BH,0
MOV DH,11
MOV DL,32
INT 10H
PRINT game3     ;print strings at the position we set above
MOV AH,2         ;set curse at the middle of the page
MOV BH,0
MOV DH,12
MOV DL,32
INT 10H
PRINT game4     ;print strings at the position we set above
MOV AH,2         ;set curse at the middle of the page
MOV BH,0
MOV DH,14
MOV DL,26
INT 10H
print game5     ;print strings at the position we set above
MOV AH,2         ;set curse at the middle of the page
MOV BH,0
MOV DH,15
MOV DL,26
INT 10H
print game6      ;print strings at the position we set above
ret
gamemainlogic endp

enter proc
mov dx,10       ;this program for nextline
mov ah,2
int 21h
mov dx,13
mov ah,2
int 21h
ret
enter endp
rectuangle proc
CALL COLOR        ;call the funtion inwhich define background page
mov ah,06          ;for making rectuagle shape
mov al,0           ;
mov bh,10101010b   ;
mov ch,3           ;       ;rectangle
mov cl,21          ;
mov dh,11          ;
mov dl,59          ;
int 10h            ;for making rectuagle shape
call work1    ;call this for for print string on the page 
mov ah,1      ;take input
int 21h
cmp al,52     ;compare input if input is 4 
je l1         ;then jump to print correct point
jmp l2        ;else jump to print worng point
l1:
call enter
print str5    ;print str5 if your input is correct
mov s1,1      ;add 1 to correct point because you give correct answer 
add s1,48     ;add 48 in correct point for ascii
mov s12,0     ;assign 0 value in wrong point because you give correct answer 
add s12,48    ;add 48 in correct point for ascii
jmp l3
l2:
call enter
print str6    ;print str6 if your input is worng
mov s12,1     ;add 1 to worng point because you give worng answer
add s12,48    ;add 48 in correct point for ascii
mov s1,0      ;assign 0 value in correct point because you give worng answer
add s1,48     ;add 48 in correct point for ascii
l3:
call enter    ;for next line
print str8    ;print strings that your answer is wrong or correct
mov ah,2      ;set curse
mov bh,0
mov dh,8
mov dl,33
int 10h    ;;;;;;;;;;;;;;;
print str00  ;print name of the shape
call work3   ;call this for print correct and wrong point
mov ah,1     ;take input for wait to go the next page
int 21h
ret
rectuangle endp
square proc
CALL COLOR      ;call the funtion inwhich define background page        
mov ah,07            ;for making square shape          
mov al,0             ;
mov bh,10101010b     ;
mov ch,2             ;
mov cl,26            ;
mov dh,10            ;     ;square
mov dl,51            ;
int 10h              ;for making rectuagle shape
call work1           ;call this for for print string on the page 
mov ah,1             ;take input
int 21h
cmp al,50            ;compare input if input is 2 
je l111              ;then jump to print correct point
jmp l222             ;else jump to print worng point
l111:
call enter    ;for nextline
print str5    ;print str5 if your input is correct
add s1,1      ;add 1 to correct point because you give correct answer 
jmp l333
l222:
call enter
print str6    ;print str6 if your input is worng
add s12,1     ;add 1 to worng point because you give worng answer
l333:
call enter    ;for next line
print str8    ;print strings that your answer is wrong or correct
mov ah,2      ;set curse
mov bh,0
mov dh,7
mov dl,35
int 10h    
print str01  ;print name of the shape
call work3   ;call this for print correct and wrong point
mov ah,1     ;take input for wait to go the next page
int 21h
ret
square endp
parallogram proc
CALL COLOR      ;call the funtion inwhich define background page
loopo:                 ;for making parallelogram shape
mov ah,07              ;
mov al,0               ;
mov bh,10101010b       ;
mov ch,str11           ;
mov cl,str22           ;            ;parallelogram
mov dh,str33           ;
mov dl,str44           ;
int 10h                ; 
inc str11              ;
dec str22              ;
inc str33              ;
dec str44              ;
cmp str11,11           ;
jne loopo              ;for making parallelogram shape
call work1           ;call this for for print string on the page 
mov ah,1             ;take input
int 21h                
cmp al,51            ;compare input if input is 3
je lll1              ;then jump to print correct point
jmp lll2             ;else jump to print worng point
lll1:
call enter    ;for nextline
print str5    ;print str5 if your input is correct
add s1,1      ;add 1 to correct point because you give correct answer 
jmp lll3
lll2:
call enter
print str6    ;print str6 if your input is worng
add s12,1     ;add 1 to worng point because you give worng answer
lll3:
call enter    ;for next line
print str8    ;print strings that your answer is wrong or correct
mov ah,2      ;set curse
mov bh,0
mov dh,7
mov dl,32
int 10h    ;;;;;;;;;;;;;;;
print str02  ;print name of the shape
call work3   ;call this for print correct and wrong point
mov ah,1     ;take input for wait to go the next page
int 21h
mov str11,3   ;mov shape value in variable again beacse we call this
mov str22,25  ;program so many times so that why we move again for save value
mov str33,3
mov str44,55
ret
parallogram endp
triangle proc
CALL COLOR      ;call the funtion inwhich define background page
loopo1:                  ;for making triangle shape
mov ah,7                 ;
mov bh,10101010b         ;
mov ch,str111            ;
mov cl,str222            ;
mov dh,str333            ;
mov dl,str444            ;      ;triangle
int 10h                  ;
inc str111               ;
dec str222               ;
inc str333               ;
inc str444               ;
cmp str111,12            ;
jne loopo1               ;for making triangle shape
call work1           ;call this for for print string on the page 
mov ah,1             ;take input
int 21h
cmp al,49            ;compare input if input is 1
je t1                ;then jump to print correct point
jmp t2               ;else jump to print worng point
t1:
call enter    ;for nextline
print str5    ;print str5 if your input is correct
add s1,1      ;add 1 to correct point because you give correct answer 
jmp t3
t2:
call enter
print str6    ;print str6 if your input is worng
add s12,1     ;add 1 to worng point because you give worng answer
t3:
call enter    ;for next line
print str8    ;print strings that your answer is wrong or correct
mov ah,2      ;set curse
mov bh,0
mov dh,9
mov dl,35
int 10h   
print str03  ;print name of the shape
call work3   ;call this for print correct and wrong point
mov ah,1     ;take input for wait to go the next page
int 21h
mov str111,2   ;mov shape value in variable again beacse we call this
mov str222,38  ;program so many times so that why we move again for save value
mov str333,2
mov str444,38
ret
triangle endp
rigthangletriangle proc
CALL COLOR      ;call the funtion inwhich define background page
loopo2:                  ;for making rigth angle triangle shape
mov ah,7                 ;
mov al,0                 ;
mov bh,10101010b         ;
mov ch,str1111           ;
mov cl,str2222           ;        ;rigth angle triangle
mov dh,str3333           ;
mov dl,str4444           ;
int 10h                  ;
inc str1111              ;
inc str3333              ;
inc str4444              ;
cmp str1111,13           ;
jne loopo2               ;for making rigth angle triangle shape
call work2           ;call this for for print string on the page 
mov ah,1             ;take input
int 21h
cmp al,50            ;compare input if input is 2
je a1                ;then jump to print correct point
jmp a2               ;else jump to print worng point
a1:
call enter    ;for nextline
print str5    ;print str5 if your input is correct
add s1,1      ;add 1 to correct point because you give correct answer 
jmp a3
a2:
call enter
print str6    ;print str6 if your input is worng
add s12,1     ;add 1 to worng point because you give worng answer
a3:
call enter    ;for next line
print str8    ;print strings that your answer is wrong or correct
mov ah,2      ;set curse
mov bh,0
mov dh,11
mov dl,36
int 10h    
print str04    ;print name of the shape
mov ah,2       ;set curse
mov bh,0
mov dh,12                                ;;;;;;
mov dl,36
int 10h    ;;;;;;;;;;;;;;;
print str03     ;print name of the shape
call work3   ;call this for print correct and wrong point
mov ah,1     ;take input for wait to go the next page
int 21h
mov str1111,2  ;mov shape value in variable again beacse we call this
mov str2222,36 ;program so many times so that why we move again for save value
mov str3333,2
mov str4444,36
ret
rigthangletriangle endp
diamond proc
CALL COLOR      ;call the funtion inwhich define background page
loopo3:                  ;for making diamond shape
mov ah,7                 ;
mov al,0                 ;
mov bh,10101010b         ;
mov ch,strt1             ;
mov cl,strt2             ;
mov dh,strt3             ;     ;diamond
mov dl,strt4             ;
int 10h                  ;
inc strt1                ;
dec strt2                ;
inc strt3                ;
inc strt4                ;
cmp strt1,8              ;
jne loopo3               ;
dec strt1                ;
inc strt2                ;
dec strt3                ;
dec strt4                ;
loopo4:                  ;
inc strt1                ;
inc strt2                ;
inc strt3                ;
dec strt4                ;
mov ah,7                 ;
mov al,0                 ;
mov bh,10101010b         ;
mov ch,strt1             ;
mov cl,strt2             ;
mov dh,strt3             ;
mov dl,strt4             ;
int 10h                  ;
cmp strt1,12             ;
jne loopo4               ;for making diamond shape
call work2           ;call this for for print string on the page 
mov ah,1             ;take input
int 21h                  
cmp al,49            ;compare input if input is 1    
je b1                ;then jump to print correct point    
jmp b2               ;else jump to print worng point    
b1:                     
call enter    ;for nextline
print str5    ;print str5 if your input is correct
add s1,1      ;add 1 to correct point because you give correct answer 
jmp b3
b2:
call enter
print str6    ;print str6 if your input is worng
add s12,1     ;add 1 to worng point because you give worng answer
b3:
call enter    ;for next line
print str8    ;print strings that your answer is wrong or correct
mov ah,2      ;set curse
mov bh,0
mov dh,7
mov dl,35
int 10h    
print str05     ;print name of the shape
call work3   ;call this for print correct and wrong point
mov ah,1     ;take input for wait to go the next page
int 21h
mov strt1,2    ;mov shape value in variable again beacse we call this
mov strt2,38   ;program so many times so that why we move again for save value
mov strt3,2
mov strt4,38
ret
diamond endp
octagon proc
CALL COLOR      ;call the funtion inwhich define background page
loopo11:                  ;for making octagon shape
mov ah,7                  ;
mov al,0                  ;
mov bh,10101010b          ;
mov ch,strt5              ;
mov cl,strt6              ;
mov dh,strt7              ;
mov dl,strt8              ;
int 10h                   ;
inc strt5                 ;        ;octagon
dec strt6                 ;
inc strt7                 ;
inc strt8                 ;
cmp strt5,6               ;
jne loopo11               ;
dec strt5                 ;
inc strt6                 ;
dec strt7                 ;
dec strt8                 ;
mov cx,3                  ;
loopo22:                  ;
push cx                   ;
inc strt5                 ;
inc strt7                 ;
mov ah,7                  ;
mov al,0                  ;
mov bh,10101010b          ;
mov ch,strt5              ;
mov cl,strt6              ;
mov dh,strt7              ;
mov dl,strt8              ;
int 10h                   ;
pop cx                    ;
loop loopo22              ;
loopo33:                  ;
inc strt5                 ;
inc strt7                 ;
dec strt8                 ;
inc strt6                 ;
mov ah,7                  ;
mov al,0                  ;
mov bh,10101010b          ;
mov ch,strt5              ;
mov cl,strt6              ;
mov dh,strt7              ;
mov dl,strt8              ;
int 10h                   ;
cmp strt5,11              ;
jne loopo33               ;for making octagon shape
call work2           ;call this for for print string on the page 
mov ah,1             ;take input
int 21h
cmp al,51            ;compare input if input is 3
je c1                ;then jump to print correct point   
jmp c2               ;else jump to print worng point
c1:
call enter    ;for nextline
print str5    ;print str5 if your input is correct
add s1,1      ;add 1 to correct point because you give correct answer 
jmp c3
c2:
call enter
print str6    ;print str6 if your input is worng
add s12,1     ;add 1 to worng point because you give worng answer
c3:
call enter    ;for next line
print str8    ;print strings that your answer is wrong or correct
mov ah,2      ;set curse
mov bh,0
mov dh,7
mov dl,37
int 10h    
print str06     ;print name of the shape
call work3   ;call this for print correct and wrong point
mov ah,1     ;take input for wait to go the next page
int 21h
mov strt5,2     ;mov shape value in variable again beacse we call this
mov strt6,36    ;program so many times so that why we move again for save value
mov strt7,2
mov strt8,44
ret
octagon endp
triod proc
CALL COLOR      ;call the funtion inwhich define background page
LOOPL1:                  ;for making trapezoid shape
MOV AH,7                 ;       
MOV AL,0                 ;
MOV BH,10101010b         ;
MOV CH,strt11            ;
MOV CL,strt22            ;
MOV DH,strt33            ;
MOV DL,strt44            ;
INT 10H                  ;          ;trapezoid 
INC strt11               ;
inc strt33               ;
DEC strt22               ;
INC strt44               ;
CMP strt11,10            ;
JNE LOOPL1               ;for making trapezoid shape
call work2           ;call this for for print string on the page 
mov ah,1             ;take input
int 21h                  
cmp al,52            ;compare input if input is 4   
je d1                ;then jump to print correct point     
jmp d2               ;else jump to print worng point   
d1:                      
call enter    ;for nextline
print str5    ;print str5 if your input is correct
add s1,1      ;add 1 to correct point because you give correct answer 
jmp d3
d2:
call enter
print str6    ;print str6 if your input is worng
add s12,1     ;add 1 to worng point because you give worng answer
d3:
call enter    ;for next line
print str8    ;print strings that your answer is wrong or correct
mov ah,2      ;set curse
mov bh,0
mov dh,8
mov dl,36
int 10h    ;;;;;;;;;;;;;;;
print str07     ;print name of the shape
call work3   ;call this for print correct and wrong point
mov ah,1     ;take input for wait to go the next page
int 21h
mov strt11,2    ;mov shape value in variable again beacse we call this
mov strt22,34   ;program so many times so that why we move again for save value
mov strt33,2
mov strt44,46
ret
triod endp
end main
