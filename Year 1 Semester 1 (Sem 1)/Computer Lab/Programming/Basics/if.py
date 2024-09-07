# positive/negative numnber

a = int(input())

if a >= 0:
    print('The number you entered is positive')
else:
    print('The number you entered is negative')

# leap year

a = int(input())

if a % 4 == 0 and a % 100 != 0:
    print(f'{a} is a leap year')
elif a % 400 == 0:
    print(f'{a} is a leap year')
else:
    print(f'{a} is not a leap year')

# roots of equation

a = int(input())
b = int(input())
c = int(input())

print((-b + (b**2 - 4*a*c)**0.5)/2*a, (-b - (b**2 - 4*a*c)**0.5)/2*a)

# CGPA program

cgpa = float(input())

if cgpa >= 9:
    print('Outstanding')
elif cgpa >= 8:
    print('Excellent')
elif cgpa >= 7:
    print('Good')
elif cgpa >= 6:
    print('Average')
elif cgpa >= 5:
    print('Better')
else:
    print('Poor')