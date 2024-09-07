def is_prime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def factors(n):
    factors = []
    for i in range(1, n + 1):
        if n % i == 0:
            if i not in factors:
                factors.append(i)
    return factors

def factorial(n):
    if n == 1:
        return 1;
    return factorial(n - 1) * n

def is_even(n):
    return n % 2 == 0

def is_odd(n):
    return n % 2 == 1

def is_palindrome(n):
    return str(n) == str(n)[::-1]