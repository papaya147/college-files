num = int(input())

while num // 10 != 0:
    num = num // 10 + num % 10
    
print(num)