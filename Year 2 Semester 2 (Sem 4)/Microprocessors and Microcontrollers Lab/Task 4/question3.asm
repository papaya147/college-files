ORG 0000H
SW1 EQU P1.0
MAIN: MOV TMOD, #20H
MOV TH1, #-3
MOV SCON, #50H
SETB TR1
SETB SW1
S1: JB SW1, NEXT
MOV DPTR, #STR1
FN: CLR A
MOVC A, @A+DPTR
JZ S1
ACALL SENDCOM
INC DPTR
SJMP FN
NEXT: MOV DPTR, #STR2
LN: CLR A
MOVC A, @A+DPTR
JZ S1
ACALL SENDCOM
INC DPTR
SJMP LN
SENDCOM: MOV SBUF, A
HERE: JNB TI, HERE
CLR TI
RET
STR1: DB "VIT"
STR2: DB "University"
END