complex1 = complex(input())
complex2 = complex(input())

sum = complex1 + complex2
diff = complex1 - complex2
prod = complex1 * complex2
quot = complex1 / complex2

print(sum)
print(diff)
print(prod)
print(round(quot.real, 2) + round(quot.imag, 2) * 1j)