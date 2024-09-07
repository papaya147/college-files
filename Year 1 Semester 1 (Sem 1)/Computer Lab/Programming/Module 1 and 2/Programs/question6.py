s1 = int(input())
s2 = int(input())
s3 = int(input())

semi_per = (s1 + s2 + s3) / 2
area = (semi_per * (semi_per - s1) * (semi_per - s2) * (semi_per - s3)) ** 0.5

print("{:.2f}".format(area))