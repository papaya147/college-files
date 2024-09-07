import numpy as np

def get_deter(matrix):
    if len(matrix) != len(matrix[0]):
        return 'Not Square Matrix!'
    if len(matrix) == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    matrix = np.array(matrix)
    sum = 0
    new_mat = np.delete(matrix, 0, 0)
    for i in range(len(matrix[0])):
        sum += matrix[0][i] * ((-1)**i) * get_deter(np.delete(new_mat, i, 1))
    return sum

n = [[1,3,7,3],[3,6,7,1],[1,6,3,3],[5,3,9,3]]
print(get_deter(n))