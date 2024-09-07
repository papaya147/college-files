import numpy as n


def inverse(a, n):
    return a ** (n - 2) % n


def double(a, n, point):
    x1, y1 = point[0], point[1]
    l = ((3 * x1 * x1 + a) * inverse(2 * y1, n)) % n
    print("lambda: ", l)
    x3 = (l * l - 2 * x1) % n
    y3 = (l * (x1 - x3) - y1) % n
    return x3, y3


def add(a, n, point1, point2):
    x1, y1 = point1[0], point1[1]
    x2, y2 = point2[0], point2[1]
    if x1 == x2 and y1 == y2:
        return double(a, n, point1)
    l = ((y2 - y1) * inverse(x2 - x1, n)) % n
    x3 = (l * l - x1 - x2) % n
    y3 = (l * (x1 - x3) - y1) % n
    return x3, y3


a = 1
n = 11

point1 = (3, 6)
point2 = (10, 2)

print(add(a, n, point1, point2))
