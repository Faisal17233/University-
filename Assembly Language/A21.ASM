;PROGRAM TO ADD TWO NUMBERS
DOSSEG                           ;CORRECTS ANY SEGMENT LINE MISTAKE
.MODEL SMALL                     ;SIZE OF MEMORY TO RESERVE
.STACK 100H                      ;SIZE OF STACK
.DATA                            ;FOR VARIABLES
.CODE                            ;FOR INSTRUCTIONS
MAIN PROC                        ;MAIN PROCEDURE START
MOV CL,4                         ;STORES 4 IN CL REGISTER
MOV DL,2                         ;STORES 2 IN DL REGISTER
ADD DL,CL                        ;ADD VALUES IN BOTH REGISTER
ADD DL,48                        ;ADDING 48 IN DL REGISTER
MOV AH,2                         ;PRINTING
INT 21H
MOV AH,4CH                       ;EXITING REGISTER
INT 21H
MAIN ENDP                        ;MAIN PROCEDURE END
END MAIN
