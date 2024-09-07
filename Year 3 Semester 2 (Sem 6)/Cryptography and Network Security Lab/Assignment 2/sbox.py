def apply(sbox, code):
    row = code[0] * 2 + code[5]
    col = code[1] * 8 + code[2] * 4 + code[3] * 2 + code[4]

    sub_val = sbox[row][col]
    return binary(sub_val)


def binary(num):
    return bin(num)[2:].zfill(4)


sbox = [
    [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
    [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
    [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
    [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]
]

code_raw = input("enter code to substitute: ").split()
code_joined = ",".join(code_raw)
code = eval(f"[{code_joined}]")

print(f"ouput from s-box application: {apply(sbox, code)}")
