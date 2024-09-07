import struct


def pad(message):
    message_bits = 8 * len(message)
    padded_message = message.encode('utf-8') + b'\x80'
    padding_length = (896 - (message_bits + 1)) % 1024
    padded_message += b'\x00' * (padding_length // 8)
    print(message_bits)
    padded_message += message_bits.to_bytes(16, byteorder='big')
    return [struct.unpack('>Q', padded_message[i:i+8])[0] for i in range(0, len(padded_message), 8)]


def circular_left_shift(n, a, bits):
    return ((n << a) | (n >> (bits - a))) & ((1 << bits) - 1)


def sigma_0(x):
    return circular_left_shift(x, 1, 64) ^ circular_left_shift(x, 8, 64) ^ (x << 7)


def sigma_1(x):
    return circular_left_shift(x, 19, 64) ^ circular_left_shift(x, 61, 64) ^ (x << 6)


def sequence(padded):
    seq = [p for p in padded]
    for i in range(16, 80):
        seq.append((
            sigma_1(seq[i - 2]) + seq[i - 7] +
            sigma_0(seq[i - 15]) + seq[i - 16]
        ) & (2 ** 64 - 1))
    return seq


word = input("enter word: ")
padded = pad(word)
input_sequence = sequence(padded)
j = 0
for i in input_sequence:
    if j % 4 == 0 and j != 0:
        print("")
    print(f"{format(i, '016x')} ", end="")
    j += 1
