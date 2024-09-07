def substring_position(s1, s2, n):
    for i in range(len(s1)):
        if s1[i : i + len(s2)] == s2:
            return i - n
    
    return 'NotAvailable'

s1 = input()
s2 = input()
n = int(input())

print(substring_position(s1, s2, n))