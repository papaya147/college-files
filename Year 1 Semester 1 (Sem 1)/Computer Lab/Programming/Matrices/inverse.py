from fractions import Fraction
import determinant as dt
import numpy as np

def transpose(matrix):
    for i in range(len(matrix)):
        for j in range(0, i):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    return matrix

def minors(matrix):
    new_mat = np.array(matrix)
    for i in range(len(new_mat)):
        for j in range(len(new_mat[i])):
            reduced = np.delete(np.delete(new_mat, i, 0), j, 1)
            matrix[i][j] = dt.get_deter(reduced)
    return list(matrix)

def cofactors(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j] *= (-1)**(i + j)
    return matrix

mat = eval(input())
adjugate = cofactors(minors(transpose([x[:] for x in mat])))
determinant = dt.get_deter(mat)
inverse = np.array(adjugate) / determinant
print(inverse)