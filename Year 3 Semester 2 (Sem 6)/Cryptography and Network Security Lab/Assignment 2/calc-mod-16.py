def add(x, y, mod):
    return (x + y) % mod


def sub(x, y, mod):
    return (x - y) % mod


def mult(x, y, mod):
    return (x * y) % mod


def inverse(x, mod):
    return (x ** (mod - 2)) % mod


def div(x, y, mod):
    return mult(x, inverse(y, mod), mod)


mod = 2**4
m = int(input("enter number 1: "))
n = int(input("enter number 2: "))

print()
print(f"sum:        {add(m, n, mod)}")
print(f"difference: {sub(m, n, mod)}")
print(f"product:    {mult(m, n, mod)}")
print(f"quotient:   {div(m, n, mod)}")
