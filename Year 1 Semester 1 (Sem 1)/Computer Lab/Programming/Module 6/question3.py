def scores(student_marks):
    marks = student_marks.values()
    mean_marks = sum(marks) // len(marks)
    above = []
    mean = []
    below = []
    for i, j in student_marks.items():
        if j > mean_marks:
            above.append(i)
        elif j == mean_marks:
            mean.append(i)
        else:
            below.append(i)
    return mean, above, below

student_marks = eval(input())
mean, above, below = scores(student_marks)
if len(mean) != 0:
    print(', '.join(mean))
if len(above) != 0:
    print(', '.join(above))
if len(below) != 0:
    print(', '.join(below))