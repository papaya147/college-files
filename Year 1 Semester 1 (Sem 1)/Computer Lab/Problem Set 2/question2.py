n = int(input())
m = int(input())

sum1 = sum2 = sum3 = 0

while n > 0:
    rem = n % 10
    n = n // 10
    if rem > m:
        sum1 += 1
    elif rem < m:
        sum2 += 1
    else:
        sum3 += 1

print(sum1)
print(sum2)
print(sum3)