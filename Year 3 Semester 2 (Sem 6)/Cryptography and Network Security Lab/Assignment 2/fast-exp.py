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


m = int(input("enter base: "))
n = int(input("enter power: "))
mod = int(input("enter mod: "))

print(f"{m}^{n} mod {mod} is {exponentiate(m, n, mod)}")
