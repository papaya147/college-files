import re

sen = input()
words = sen.split(' ')

for word in words:
    if re.match('^[aeiouAEIOU]', word):
        print(word)