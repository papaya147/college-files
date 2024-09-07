def binary_list(n):
    binary = []
    while n > 0:
        binary.append(int(n % 2))
        n = int(n / 2)
    return binary


def exponentiate(m, n, mod):
    binary_power = binary_list(n)
    current_val = m % mod
    prod = 1
    for i in binary_power:
        if i == 1:
            prod = (prod * current_val) % mod
        current_val = (current_val * current_val) % mod
    return prod % mod


def factors(n):
    res = []
    i = 2
    while n != 1:
        if n % i == 0:
            n //= i
            res.append(i)
            continue
        i += 1
    return res


def totient(n):
    f = factors(n)
    t = 1
    count = 1
    for i in range(len(f) - 1):
        if f[i] == f[i + 1]:
            count += 1
        else:
            t *= f[i] ** count - f[i] ** (count - 1)
            count = 1
    t *= f[len(f) - 1] ** count - f[len(f) - 1] ** (count - 1)
    return t


# key setup
p = int(input("enter p: "))
q = int(input("enter q: "))
e = int(input("enter e: "))
n = p * q
totient_n = (p - 1) * (q - 1)
d = exponentiate(e, totient(totient_n) - 1, totient_n)

# message encryption
m = int(input("enter m: "))
c = exponentiate(m, e, n)
print(f"encrypted message is {c}")

# message decryption
decrypted = exponentiate(c, d, n)
print(f"decrypted message is {decrypted}")
