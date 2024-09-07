def fibonacci(n, m, p):
    if p == 1:
        return [n]
    l = [n]
    for i in fibonacci(m, n + m, p - 1):
        l.append(i)
    return l

n = int(input())
m = int(input())
p = int(input())

for i in fibonacci(n, m, p):
    print(f'{i} ', end = '')
