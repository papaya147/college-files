n = int(input())

if n < 0 or n > 100:
    print('Invalid')
else:
    if n > 90:
        print('S')
    elif n > 80:
        print('A')
    elif n > 70:
        print('B')
    elif n > 60:
        print('C')
    elif n >= 50:
        print('D')
    else:
        print('F')