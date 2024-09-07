n = int(input())
list = []

for i in range(n):
    list.append(int(input()))

compare = int(input())
sum1 = sum2 = sum3 = 0

for i in list:
    if i > compare:
        sum1 += 1
    elif i < compare:
        sum2 += 1
    else:
        sum3 += 1

print(list)
print(sum1)
print(sum2)
print(sum3)