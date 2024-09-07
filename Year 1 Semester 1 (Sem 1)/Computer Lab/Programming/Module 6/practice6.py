def fibonacci(n, a = 0, b = 1,):
    if n == 0:
        return
    print(a, end = ' ')
    fibonacci(n - 1, b, a + b)

a = int(input())
b = int(input())
n = int(input())
fibonacci(n, a, b)