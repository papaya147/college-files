ORG 0000H
MOV TMOD, #20H
MOV TH1, #-3
MOV SCON, #50H
SETB TR1
HERE: JNB RI, HERE
MOV A, SBUF
MOV P2, A
CLR RI
SJMP HERE
END