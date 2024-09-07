marks = float(input())
if marks <= 0:
    print('Enter appropriate Mark')
else:
    session = input()
    if marks >= 80:
        if session == 'T':
            print('{:.2f}'.format(marks * 1.08))
        if session == 'L':
            print('{:.2f}'.format(marks * 1.06))
    elif marks >= 60:
        if session == 'T':
            print('{:.2f}'.format(marks * 1.06))
        if session == 'L':
            print('{:.2f}'.format(marks * 1.04))
    elif marks >= 40:
        if session == 'T':
            print('{:.2f}'.format(marks * 1.04))
        if session == 'L':
            print('{:.2f}'.format(marks * 1.02))
    else:
        if session == 'T':
            print('{:.2f}'.format(marks))
        if session == 'L':
            print('{:.2f}'.format(marks))