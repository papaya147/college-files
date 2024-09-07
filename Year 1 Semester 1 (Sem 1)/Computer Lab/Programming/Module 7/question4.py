import pandas as pd

data1 = {'regno': ['21BDS0342', '21BDS0343'], 'studname': ['ghi', 'jkl'], 'cgpa': [5.6, 10]}
data2 = {'regno': ['21BDS0340', '21BDS0341'], 'studname': ['abc', 'def'], 'cgpa': [8.5, 9.2]}
DF1 = pd.DataFrame(data1)
DF2 = pd.DataFrame(data2)
DF3 = pd.concat([DF1, DF2])
print(DF3)