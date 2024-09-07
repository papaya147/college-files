def get_next_letter(used_letter_list, key):
    for letter in key:
        if letter not in used_letter_list:
            used_letter_list.append(letter)
            return letter
    for letter in "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if letter not in used_letter_list:
            used_letter_list.append(letter)
            return letter


def create_matrix(key):
    unique_letters = []
    matrix = []
    for x in range(5):
        letters = []
        for y in range(5):
            letters.append(get_next_letter(unique_letters, key))
        matrix.append(letters)
    return matrix


def split_pairs(text):
    if len(text) % 2 == 1:
        text += "Z"
    text_list = []
    for x in range(0, len(text), 2):
        if text[x] == text[x+1]:
            text_list.append("X" + text[x])
        else:
            text_list.append(text[x:x+2])
    return text_list


def get_letter_position(letter, matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if letter == matrix[i][j]:
                return i, j


def encrypt(plaintext_list, matrix):
    encrypted = ""
    for pair in plaintext_list:
        let1 = pair[0]
        let2 = pair[1]
        x1, y1 = get_letter_position(let1, matrix)
        x2, y2 = get_letter_position(let2, matrix)

        if y1 == y2:
            encrypted += matrix[(x1 + 1) % 5][y1]
            encrypted += matrix[(x2 + 1) % 5][y2]
        elif x1 == x2:
            encrypted += matrix[x1][(y1 + 1) % 5]
            encrypted += matrix[x2][(y2 + 1) % 5]
        else:
            encrypted += matrix[x1][y2]
            encrypted += matrix[x2][y1]

    return encrypted


def decrypt(encrypted_list, matrix):
    decrypted = ""
    for pair in encrypted_list:
        let1 = pair[0]
        let2 = pair[1]
        x1, y1 = get_letter_position(let1, matrix)
        x2, y2 = get_letter_position(let2, matrix)

        if y1 == y2:
            decrypted += matrix[(x1 - 1) % 5][y1]
            decrypted += matrix[(x2 - 1) % 5][y2]
        elif x1 == x2:
            decrypted += matrix[x1][(y1 - 1) % 5]
            decrypted += matrix[x2][(y2 - 1) % 5]
        else:
            decrypted += matrix[x1][y2]
            decrypted += matrix[x2][y1]

    return decrypted


key = input('Key: ')
plaintext = input('Plaintext: ')

# uppercasing the letters
key = key.upper()

# replacing all J with I
key = key.replace('J', 'I')

# generating the encryption matrix
matrix = create_matrix(key)

# converting plaintext to uppercase
plaintext = plaintext.upper()

# getting plaintext split into pairs
plaintext_list = split_pairs(plaintext)

# encrypting the plaintext
encrypted = encrypt(plaintext_list, matrix)
print(f'The encrypted text is: {encrypted}')

# getting encrypted split into pairs
encrypted_list = split_pairs(encrypted)

decrypted = decrypt(encrypted_list, matrix)
print(f'The decrypted text is: {decrypted}')
