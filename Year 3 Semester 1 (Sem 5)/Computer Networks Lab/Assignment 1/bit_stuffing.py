# default flag = 01111110
print('Enter bits:')
raw = input()
allowed = ['0', '1']

# checking for correct formatting (only 0's and 1's)
for i in raw:
    if i not in allowed:
        print('Invalid format!')
        exit()

# creating output frame (stuff 0 after 5 consecutive 1's)
output = ''
count = 0
for i in raw:
    output += i
    if i == '1':
        count += 1
    else:
        count = 0
    if count == 5:
        output += '0'
        count = 0
print('The output frame is:')
print(output)

# output with the f = 01111110
print('Th output frame with f is:')
print(f'01111110{output}01111110')
