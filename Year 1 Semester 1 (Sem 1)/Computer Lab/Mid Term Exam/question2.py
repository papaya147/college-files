n = int(input())
teachers = []

for i in range(n):
    id  = input().upper()
    name = input()
    phnum = input()
    teacher = ((id, name, phnum))
    print(teacher)
    teacher = [id, name, phnum]
    teachers.append(teacher)

m = int(input())
students = []

for i in range(m):
    id  = input().upper()
    name = input()
    phnum = input()
    student = [id, name, phnum]
    students.append(student)

length = m
while length % n != 0:
    length += 1
sep = int(length/n)

assign = {}
for i in teachers:
    assign[i[0]] = []
    if i != teachers[len(teachers) - 1]:
        for j in students[0 : sep]:
            assign[i[0]].append(j[0])
    else:
        for j in students[0 :]:
            assign[i[0]].append(j[0])
    del students[0 : sep]
    print(assign)
    assign = {}