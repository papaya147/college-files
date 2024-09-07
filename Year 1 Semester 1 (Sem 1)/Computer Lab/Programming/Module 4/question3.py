n = int(input())
m = int(input())
matrix = []

for i in range(n):
    new_mat = []
    for j in range(m):
        inp = input()
        try:
            inp = int(inp)
        except:
            pass
        finally:
            new_mat.append(inp)
    matrix.append(new_mat)

primary_index = int(input())
primary_value = input()
try:
    primary_value = int(primary_value)
except:
    pass

for i in matrix:
    for j in range(len(i)):
        if j == primary_index and i[j] == primary_value:
            print(i)
