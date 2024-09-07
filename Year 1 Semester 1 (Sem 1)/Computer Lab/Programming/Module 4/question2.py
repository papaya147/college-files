n = int(input())
rpn = []

for i in range(n):
    inp = input()
    try:
        inp = int(inp)
    except:
        pass
    finally:
        rpn.append(inp)

i = 0
while len(rpn) != 1:
    triple = rpn[i: i + 3]

    if type(triple[2]) is int:
        i += 1
        continue
    else:
        op = triple[2]
        if op == '/':
            sum = triple[0] / triple[1]
        elif op == '*':
            sum = triple[0] * triple[1]
        elif op == '+':
            sum = triple[0] + triple[1]
        elif op == '-':
            sum = triple[0] - triple[1]

        rpn[i: i+3] = [sum]
        i = 0

print(int(rpn[0]))
