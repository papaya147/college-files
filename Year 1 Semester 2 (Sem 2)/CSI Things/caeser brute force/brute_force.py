import re

letters = 'abcdefghijklmnopqrstuvwxyz'
values = list(letters)
num_to_let = dict(zip(range(26), values))
let_to_num = dict(zip(values, range(26)))

print('Enter encoded word: ', end = '')
word = input().strip().lower()

decodes = []

for i in range(1, 26):
    new = ''
    for j in word:
        if re.match('[^a-z]', j):
            new += j
            continue
        index = let_to_num.get(j) + i
        if index > 25:
            index -= 26
        new += num_to_let.get(index)
    print(new)