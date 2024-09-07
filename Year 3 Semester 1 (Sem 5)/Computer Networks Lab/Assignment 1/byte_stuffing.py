print('Enter bits, start with frame with f, end frame with e:')
raw = input()
allowed = ['0', '1', 'e', 'f']

# checking for correct format (f has to be starting)
if raw[0] != 'f':
    print('Invalid format!')
    exit()

# checking for correct formatting (e after f)
e_flag = False
for i in raw:
    if i not in allowed:
        print('Invalid character!')
        break

    if e_flag and i == 'f':
        e_flag = False
    if e_flag and i != 'f':
        print('Invalid format!')
        exit()
    if i == 'e':
        e_flag = True

# creating output frame (e before all f and e)
output = ''
for i in raw:
    if i == 'e' or i == 'f':
        output += 'e' + i
    else:
        output += i
print('The output frame is:')
print(output)
