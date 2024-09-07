no_students = int(input())
students = []
for i in range(no_students):
    marks = {}
    no_marks = int(input())
    for j in range(no_marks):
        m = input()
        marks[m] = int(input())
    students.append(marks)

print(students)

#students = [{'m1': 50, 'm2': 40, 'm3': 75}, {'m2': 49, 'm3': 35, 'm4': 54}, {'m1': 77, 'm2': 84, 'm4': 51}]
failed = {}
total = 0

#getting fails
for i in students:
    flag = True
    for j in i:
        if j not in failed.keys():
            failed[j] = 0
        if i[j] < 50:
            if(flag):
                total += 1
                flag = False
            failed[j] += 1
        
for i in failed:
    print(i)
    print(failed[i])
print(total)