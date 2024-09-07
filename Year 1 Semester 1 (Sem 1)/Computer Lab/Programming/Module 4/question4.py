n = int(input())
costs = ()
for i in range(n):
    items = int(input())
    info = ()
    for j in range(items):
        info += (input(), )
    sum = 0
    for j in info:
        try:
            sum += int(j)
        except:
            pass
    if i == n - 1:
        costs += ((info[0], sum))
    else:
        costs += ((info[0], sum), )
print(costs)
