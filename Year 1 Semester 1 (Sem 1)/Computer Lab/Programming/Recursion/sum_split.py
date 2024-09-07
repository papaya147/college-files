def sum_split(n, m):
    if m == 2:
        split = []
        for i in range(1, n):
            split.append([i, n - i])
        return split
    
    split = []
    for i in range(1, n - m + 2):
        remain = sum_split(n - i, m - 1)
        for j in remain:
            l = [i]
            for ele in j:
                l.append(ele)
            split.append(l)
    return split

n = int(input())
m = int(input())

for i in sum_split(n, m):
    for j in i:
        print(j, ' ', end = '')
    print('\n', end = '')