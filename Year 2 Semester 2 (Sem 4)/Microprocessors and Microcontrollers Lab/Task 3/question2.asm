ORG 0000H
MOV TMOD, #20H
MOV TH1, #00H
RESTART: MOV R0, #02H
AGAIN: SETB TR1
LOOP: JNB TF1, LOOP
CLR TR1
CLR TF1
DJNZ R0, AGAIN
CPL P2.0
SJMP RESTART
END