import pandas as pd

strings = input()
strings = strings.split(' ')
strings = pd.Series(strings)
strings.name = 'Text'

upper = strings.str.upper()
upper.name = 'Upper Case'

lower = strings.str.lower()
lower.name ='Lower Case'

length = strings.str.len()
length.name = 'Length'

DF = pd.concat([strings, upper, lower, length], axis = 1)
print(DF)