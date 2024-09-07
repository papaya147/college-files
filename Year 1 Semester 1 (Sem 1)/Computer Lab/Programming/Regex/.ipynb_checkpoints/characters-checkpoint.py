import re

pattern = r'papaya'
sequence = 'papaya'

print(True if re.match(pattern, sequence) else False) # True

# . denotes anything except new line character
pattern = r'.....' # first 5 characters will be taken
sequence = 'abhinav'

print(re.match(pattern, sequence).group()) # abhin

pattern = r'20..'
sequence1 = '2001'
sequence2 = '1999'

print(re.match(pattern, sequence1).group()) # 2001
print(True if re.match(pattern, sequence2) else False) # False

# ^ denotes 'starts with' $ denotes 'ends with'
pattern1 = r'^a'
pattern2 = r'sh$'
sequence1 = 'abhinav'
sequence2 = 'tanush'

print(re.match(pattern1, sequence1).group()) # a
print(True if re.match(pattern1, sequence2) else False) # False
print(True if re.match(pattern2, sequence1) else False) # False
print(re.match(r'd$', 'hello world')) # False
