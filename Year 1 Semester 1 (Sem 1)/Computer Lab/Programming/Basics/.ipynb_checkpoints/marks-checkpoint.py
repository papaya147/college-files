students = int(input("Number of students: "))

for i in range(students):
    m1 = float(input("Mark 1: "))
    m2 = float(input("Mark 1: "))
    m3 = float(input("Mark 1: "))
    
    average = (m1 + m2 + m3) / 3
    if average > 50:
        print(f"Student {i + 1} has passed and got {average}")
    else:
        print(f"Student {i + 1} has failed")