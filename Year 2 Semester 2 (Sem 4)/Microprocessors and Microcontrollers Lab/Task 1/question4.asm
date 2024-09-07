; registration number = 21BDS0340 (ignoring S)
; values = 2, 1, B, D, 0, 3, 4, 0
; moving values into bank 1, stack
MOV 08H, #02H
MOV 09H, #01H
MOV 0AH, #0BH
MOV 0BH, #0DH
MOV 0CH, #00H
MOV 0DH, #03H
MOV 0EH, #04H
MOV 0FH, #00H

; settings stack pointer to 0FH
MOV SP, #0FH

; popping values into bank 0, current bank
POP 07H
POP 06H
POP 05H
POP 04H
POP 03H
POP 02H
POP 01H
POP 00H

END