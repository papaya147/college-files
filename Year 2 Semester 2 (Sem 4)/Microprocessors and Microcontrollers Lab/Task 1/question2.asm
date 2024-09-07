; registration number = 21BDS0340
; grouped as 02 1B D0 03 40 (S swapped for 0)
MOV A, #02H ; A = 02H

ADD A, #1BH ; A = 1DH

ADD A, #0D0H ; A = EDH

ADD A, #03H ; A = F0H

ADD A, #40H ; A = 130H, but too many bits, A = 30H, CY = 1

END