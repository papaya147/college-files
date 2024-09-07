def simple_interest(p, n, r = 10.5):
    return p * n * r / 100

p = float(input())
n = int(input())
r = float(input())

print(simple_interest(p, n, r) if r != 0 else simple_interest(p, n))