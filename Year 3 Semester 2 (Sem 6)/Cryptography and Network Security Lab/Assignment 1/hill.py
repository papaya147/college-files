import math


def determinant(matrix):
    size = len(matrix)
    if size == 1:
        return matrix[0][0]
    if size == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    det = 0
    for i in range(size):
        new_matrix = []
        for x in range(1, size):
            new_row = []
            for y in range(size):
                if y == i:
                    continue
                new_row.append(matrix[x][y])
            new_matrix.append(new_row)
        det += matrix[0][i] * (-1) ** (i % 2) * determinant(new_matrix)
    return det


def matrix_mod_inverse(matrix, det, mod):
    inverse = []
    for x in range(len(matrix)):
        r = []
        for y in range(len(matrix[x])):
            new_matrix = []
            for i in range(len(matrix)):
                if i == x:
                    continue
                l = []
                for j in range(len(matrix)):
                    if j == y:
                        continue
                    l.append(matrix[i][j])
                new_matrix.append(l)
            r.append((-1) ** (x * len(matrix) + y)
                     * determinant(new_matrix) % mod)
        inverse.append(r)

    transpose = []
    for x in range(len(inverse)):
        l = []
        for y in range(len(inverse[x])):
            l.append((inverse[y][x] * det) % 26)
        transpose.append(l)
    return transpose


def mod_inverse(num, mod):
    num = num % mod
    i = 0
    while (i * num) % mod != 1:
        i += 1
        continue
    return i


def letters_to_numbers(text):
    text = text.upper()
    return [(ord(let) - 65) % 26 for let in text]


def numbers_to_letters(nums):
    return [chr(n + 65) for n in nums]


def list_to_square_matrix(l):
    size = int(math.sqrt(len(l)))
    matrix = []
    for x in range(size):
        vals = []
        for y in range(size):
            vals.append(l[x * size + y])
        matrix.append(vals)
    return matrix


def multiply(matrix, arr):
    res = []
    for i in matrix:
        s = 0
        for index in range(len(i)):
            s = (s + i[index] * arr[index]) % 26
        res.append(s)
    return res


key = input("Key: ")  # "GYBNQKURP"
plaintext = input("Plaintext: ")  # "ACT"

# getting numeric list of key
key_letter_list = letters_to_numbers(key)

# getting numeric list of plaintext
text_letter_list = letters_to_numbers(plaintext)

# generating matrix from key list values
matrix = list_to_square_matrix(key_letter_list)

# performing matrix multiplication to encrypt
encypted_nums = multiply(matrix, text_letter_list)

encrypted = numbers_to_letters(encypted_nums)
print(f'The encrypted text is: {"".join(encrypted)}')

# finding determinant and its mod inverse for decryption
det = determinant(matrix)
positive_determinant = det if det > 0 else -det
mod_inverse_determinant = mod_inverse(det, 26)

# getting the matrix inverse for decryption
inverse = matrix_mod_inverse(matrix, mod_inverse_determinant, 26)

# performing the decryption
decrypted_nums = multiply(inverse, encypted_nums)

decrypted = numbers_to_letters(decrypted_nums)
print(f'The decrypted text is: {"".join(decrypted)}')
