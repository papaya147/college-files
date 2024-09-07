income = float(input())

if income > 1000000:
    print(int(income * 0.04))
elif income > 500000:
    print(int(income * 0.02))
else:
    print(0)