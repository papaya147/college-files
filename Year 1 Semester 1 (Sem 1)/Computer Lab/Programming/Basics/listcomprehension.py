x = int(input("Enter number: "))
l = [[i, j, k] for i in range(x + 1) for j in range(x + 1) for k in range(x + 1)]
print(l)