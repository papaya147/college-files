import numpy as np

array = np.array(eval(input()))
mean = np.mean(array)
std_dev = np.std(array)
var = np.var(array)
print(mean)
print(std_dev)
print(var)