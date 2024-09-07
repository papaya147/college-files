import numpy as np

marks = []
commerce = []
for i in range(5):
    inp = eval(input().strip().split(' ')[-1])
    commerce.append(inp[-1])
    for j in inp:
        marks.append(j)
marks = np.array(marks)
commerce = np.array(commerce)
fail = marks[marks < 50]
dist = marks[marks > 90]
commerce = commerce[commerce > 50]
print(fail)
print(dist)
print(commerce)