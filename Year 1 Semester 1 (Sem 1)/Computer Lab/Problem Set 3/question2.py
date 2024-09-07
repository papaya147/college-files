# Import Regex
# Read Sentence
# Initialise Words by splitting Sentence by space
# Read Start
# Read End
# Loop through Words with I
# 	If lowercase I starts with Start and ends with End
# 		Display I

import re

sen = input()
words = sen.split(' ')
start = input()
end = input()

for i in words:
    # checking if I starts with start variable and ends with end variable
    if re.match('^' + start, i.lower()) and re.match('.*' + end + '$', i.lower()): 
        print(i)