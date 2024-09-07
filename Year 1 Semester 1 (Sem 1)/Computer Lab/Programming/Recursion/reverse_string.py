def reverse(n):
    if len(n) == 1:
        return n
    return reverse(n[1:]) + n[:1]

print(reverse(input()))