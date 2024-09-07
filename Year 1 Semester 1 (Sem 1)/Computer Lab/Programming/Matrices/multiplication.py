import numpy as np

def multiply(mat1, mat2):
    if len(mat1[0]) != len(mat2):
        return 'Matrices not multiplicable'
    res = []
    mat1, mat2 = np.array(mat1), np.array(mat2)

    for i in range(len(mat1)):
        res.append([])
        for j in range(len(mat2[0])):
            res[i].append(sum(mat1[i, :] * mat2[:, j]))
    return res

mat1 = eval(input())
mat2 = eval(input())
mat1 = [[4, 5, 7], [2, 1, 0], [4, 2, 1]]
mat2 = [[2], [8], [1]]
print(multiply(mat1, mat2))