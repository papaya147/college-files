num = int(input())

if num < 0:
    print("Enter only positive number")
else:
    if num % 2 == 0:
        i = 2
    else:
        i = 1
        
    while i <= num:
        fact = 1
        j = 2
        while j <= i:
            fact *= j
            j += 1
        print(i, fact)
        i += 2