ORG 0200H
DB "Abhinav Dinesh Srivatsa (21BDS0340)"
ORG 0000H
MOV DPTR, #0200H
MOV TMOD, #20H
MOV TH1, #-6
MOV SCON, #50H
SETB TR1
AGAIN: MOVC A, @A+DPTR
MOV SBUF, A
CLR A
INC DPTR
HERE: JNB TI, HERE
CLR TI
SJMP AGAIN
END