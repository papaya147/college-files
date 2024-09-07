; registration number = 21BDS0340 (ignoring S)
; values = 2, 1, B, D, 0, 3, 4, 0
; moving values into bank 0
MOV R0, #02H
MOV R1, #01H
MOV R2, #0BH
MOV R3, #0DH
MOV R4, #00H
MOV R5, #03H
MOV R6, #04H
MOV R7, #00H

; pushing into stack, bank 1
PUSH 00H
PUSH 01H
PUSH 02H
PUSH 03H
PUSH 04H
PUSH 05H
PUSH 06H
PUSH 07H

END