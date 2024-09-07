n = input().split(',')
m = input().split(',')
length = len(m)

while length % len(n) != 0:
    length += 1

sep = int(length/len(n))
print(sep)
assign = []

while len(n) != 0:
    assign.append(n[0])
    del n[0]
    if len(n) != 0:
        for i in m[0 : sep]:
            assign.append(i)
    else:
        for i in m[0 :]:
            assign.append(i)
    del m[0 : sep]
    print(assign)
    assign = []