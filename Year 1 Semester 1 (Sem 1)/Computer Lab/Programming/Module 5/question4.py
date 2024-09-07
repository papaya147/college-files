import re

sen = input()
words = sen.replace(',', '').split(' ')
students = []
marks = []

for word in words:
    if re.match('^[A-Z]', word):
        students.append(word)
    elif re.match('[0-9]', word):
        marks.append(word)

print(marks)
print(students)