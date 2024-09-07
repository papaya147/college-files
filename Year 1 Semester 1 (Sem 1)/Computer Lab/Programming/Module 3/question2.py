s = int(input())
if s < 0:
    print('Enter Positive Number Only')
else:
    if s <= 10:
        print(s * 15)
    elif s <= 90:
        print(150 + (s - 10) * 8)
    else:
        print(150 + 720 + (s - 100) * 6)