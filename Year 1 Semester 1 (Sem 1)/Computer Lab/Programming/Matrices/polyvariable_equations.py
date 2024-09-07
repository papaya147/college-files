import numpy as np

def solve(mat: list, ans: list):
    try:
        if len(mat) != len(ans) or len(mat[0]) != len(ans):
            return 'Matrix length and answers should be same length'
    except:
        return 'Matrix length and answers should be same length'

    mat = np.array(mat).astype('float32')
    ans = np.array(ans).astype('float32')

    for i in range(len(mat)):
        den = float(mat[i][i])
        mat[i] = mat[i] / den
        ans[i] = ans[i] /den

        for j in range(len(mat)):
            if i == j:
                continue
            sub = -mat[j][i]
            mat[j] = mat[j] + sub * mat[i]
            ans[j] = ans[j] + sub * ans[i]
    
    return list(ans)

matrix = eval(input()) # matrix = [[2, 5, 2], [3, -2, 4], [-6, 1, -7]]
answers = eval(input()) # answers = [-38, 17, -12]
x = 1
res = solve(matrix, answers)
if type(res) == list:
    for i in solve(matrix, answers):
        print(f'x{x}: {round(i, 1)}')
        x += 1
else:
    print(res)