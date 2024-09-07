import numpy as np

students = [('john', 164.5, 'XA'), ('mark', 188.3, 'XB'), ('zack', 178.7, 'XB')]
data_types = [('name', 'S10'), ('height', float), ('class', 'S4')]
students = np.array(students, dtype = data_types)
students = np.sort(students, order = ['class', 'height'])
print(students)