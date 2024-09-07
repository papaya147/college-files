n = int(input())
comps = {}

for i in range(n):
    m = int(input())
    for i in range(m):
        model = input()
        comps[model] = int(input())

lower = int(input())
upper = int(input())

for i in comps:
    if comps[i] >= lower and comps[i] <= upper:
        print(i)
        print(comps[i])