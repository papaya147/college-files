import re

a = input()
if re.match('^\d{10}$', a):
    print('Valid')
else:
    print('Invalid')
