ORG 0000H
LJMP MAIN
ORG 001BH
CPL P2.1
MOV TH1, #0FEH
MOV TL1, #33H
RETI
ORG 0030H
MAIN: SETB P2.1
MOV IE, #88H
MOV TMOD, #10H
MOV TH1, #0FEH
MOV TL1, #33H
LOOP: MOV A, P0
MOV P1, A
SETB TR1
SJMP LOOP
END