# Import Regex
# Read Sentence
# Initialise Words by splitting Sentence by space
# Read Start
# Read End
# Loop through Words with I
# 	If lowercase I starts with Start
# 		Display I
# Loop through Words with I
# 	If lowercase I ends with End
# 		Display I

import re

sen = input()
words = sen.split(' ')
start = input()
end = input()

for i in words:
    # checking if I starts with start variable
    if re.match('^' + start, i.lower()): 
        print(i)

for i in words:
    # checking if I ends with end variable
    if re.match('.*' + end + '$', i.lower()):
        print(i)