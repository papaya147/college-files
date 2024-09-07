sen = input()

for i in sen:
    if i.islower():
        print(i.upper(), end = '')
    elif i.upper():
        print(i.lower(), end = '')
    else:
        print(i, end = '')