import re

n = input().lower()
regex = r'^[0-9][0-9][a-z]{3}[0-9]{4}$'

if re.match(regex, n):
    print('Valid')
else:
    print('Invalid')