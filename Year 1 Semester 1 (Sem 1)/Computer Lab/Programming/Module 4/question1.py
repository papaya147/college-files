n = int(input())
numbers = []

for i in range(n):
    numbers.append(int(input()))

flag = False
for i in range(1, n - 1):
    left = numbers[:i]
    right = numbers[i + 1:]

    if sum(left) == sum(right):
        flag = True
        print(i)

if(not flag):
    print(0)