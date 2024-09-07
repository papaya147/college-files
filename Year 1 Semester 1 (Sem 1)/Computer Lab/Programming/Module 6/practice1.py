def area(p, q, r):
    # checking if points in same line
    if (p[0] == q[0] and q[0] == r[0]) or (p[1] == q[1] and q[1] == r[1]):
        print('Points are linear.')
        return 0
    
    return ((p[0] - r[0]) * (q[1] - p[1]) - (p[0] - q[0]) * (r[1] - p[1])) / 2

points = []
for i in range(3):
    points.append(eval(input()))

print(area(points[0], points[1], points[2]))