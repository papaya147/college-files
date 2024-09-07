def letters_to_numbers(text):
    text = text.upper()
    return [(ord(let) - 65) % 26 for let in text]


def numbers_to_letters(nums):
    return [chr(n + 65) for n in nums]


def encrypt(key, plaintext):
    key_size = len(key)

    encrypted = []
    for i in range(len(plaintext)):
        encrypted.append((plaintext[i] + key[i % key_size]) % 26)

    return encrypted


def decrypt(key, ciphertext):
    key_size = len(key)

    decrypted = []
    for i in range(len(ciphertext)):
        decrypted.append((ciphertext[i] - key[i % key_size]) % 26)

    return decrypted


key = input("Key: ")
plaintext = input("Plaintext: ")

key_letter_list = letters_to_numbers(key)
plaintext_letter_list = letters_to_numbers(plaintext)

encrypted_nums = encrypt(key_letter_list, plaintext_letter_list)
encrypted = numbers_to_letters(encrypted_nums)
print(f'The encrypted text is: {"".join(encrypted)}')

decrypted_nums = decrypt(key_letter_list, encrypted_nums)
decrypted = numbers_to_letters(decrypted_nums)
print(f'The decrypted text is: {"".join(decrypted)}')
