; 1/4 sec = 0.25 sec = 250 millisec
; 250 ms / 60.7 ns = 4118616 approx machine cycles
;                 = 72 x 57203
;				  = 72 x (65536 - 8333)
ORG 0000H
MOV TMOD, #01H
SETB P2.3
QSEC:
MOV R0, #48H
LOOP:
MOV TL0, #8DH
MOV TH0, #20H
SETB TR0
AGAIN: JNB TF0, AGAIN
CLR TR0
CLR TF0
DJNZ R0, LOOP
CPL P2.3
SJMP QSEC
END