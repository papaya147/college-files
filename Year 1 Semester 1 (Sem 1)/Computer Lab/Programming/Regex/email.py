import re

n = input().lower()
regex = r'^\w+@[a-z]+\.[a-z]+$'

if re.match(regex, n):
    print('Valid')
else:
    print('Invalid')