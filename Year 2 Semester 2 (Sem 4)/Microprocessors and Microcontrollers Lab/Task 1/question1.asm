; addition
MOV A, #10H ; A = 10H
MOV R0, #20H ; A = 20H
ADD A, R0 ; A = A + R0 = 30H
MOV R0, A ; addition result stored in R0

; subtraction
MOV A, #20H ; A = 20H
MOV R1, #54H ; R1 = 54H
SUBB A, R1 ; A = A - R1 = -34H = CCH in 2's complement
MOV R1, A ; subtraction result stored in R1

; multiplication
MOV A, #0CFH ; A = CFH
MOV B, #10H ; R2 = 10H
MUL AB ; AB = A x B = CF0H
MOV R2, A ; MSB's of AB stored in R2
MOV R3, B ; LSB's of AB stored in R3

; division
MOV A, #54H ; A = 54H
MOV B, #20H ; B = 20H
DIV AB ; AB = A / B = Quotient - 2H, Remainder - 14H
MOV R4, A ; R4 = Quotient of A / B
MOV R5, B ; R5 = Remainder of A / B

END