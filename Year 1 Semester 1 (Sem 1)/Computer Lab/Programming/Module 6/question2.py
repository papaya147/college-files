def get_animals(m, n):
    # equations:
    #    x  +  y = m
    #    4x + 2y = n
    #
    # =>  x      = n/2 - m
    # =>  y      = m - x = 2m - n/2

    return n//2 - m, 2*m - n//2

count = eval(input())
m = count[0]
n = count[1]

print(get_animals(m, n))