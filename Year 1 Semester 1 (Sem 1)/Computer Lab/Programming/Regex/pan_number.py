import re

n = input().upper()
regex = r'^[A-Z]{5}\d{4}[A-Z]$'

if re.match(regex, n):
    print('Valid')
else:
    print('Invalid')