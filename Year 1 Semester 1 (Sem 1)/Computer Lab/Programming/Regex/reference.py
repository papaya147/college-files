import re

pattern = r'papaya'
sequence = 'papaya'

print(True if re.match(pattern, sequence) else False) # True

# . denotes anything except new line character

pattern = r'.....' # first 5 characters will be taken
sequence = 'abhinav'

print(re.search(pattern, sequence).group()) # abhin

pattern = r'20..'
sequence1 = '2001'
sequence2 = '1999'

print(re.search(pattern, sequence1).group()) # 2001
print(True if re.match(pattern, sequence2) else False) # False

# ^ denotes 'starts with' $ denotes 'ends with'

print(True if re.search(r'^ab', 'abhinav') else False) # True
print(True if re.search(r'^ab', 'tanush') else False) # False
print(True if re.search(r'sh$', 'abhinav') else False) # False
print(True if re.search(r'sh$', 'tanush') else False) # True

# [0-5] represents numbers between 0 and 5

print(re.findall(r'[0-5]', 'I have 3 numbers: 1, 4 and 5')) # ['3', '1', '4', '5']

# [^5] finds all characters except 5

print(re.findall(r'[^5]', '1234567891011121314151617181920')) # ['1', '2', '3', '4', '6', '7', '8', '9', '1', '0', '1', '1', '1', '2', '1', '3', '1', '4', '1', '1', '6', '1', '7', '1', '8', '1', '9', '2', '0']

# [^a] finds all characters except a

print(re.findall(r'[^a]', 'abhinav tanush')) # ['b', 'h', 'i', 'n', 'v', ' ', 't', 'n', 'u', 's', 'h']

# \s represents whitespace characters

print(''.join(re.findall(r'[^\s]', 'tanush is a little mongoose\nthis is very weird'))) # tanushisalittlemongoosethisisveryweird

# \S represents anything NOT in \s
print(''.join(re.findall(r'[^\S]', 'tanush is a little mongoose\nthis is very weird'))) #     
                                                                                        #    

# \w matches any character in [a-zA-Z0-9_]

print(''.join(re.findall(r'[^\w]', 'My number is 6382662307, my email adress is abhinav_srivatsa6@gmail.com and I am 19'))) #    ,     @.    

# \W mathes anything NOT in \w

print(''.join(re.findall(r'[^\W]', 'My number is 6382662307, my email adress is abhinav_srivatsa6@gmail.com and I am 19'))) # Mynumberis6382662307myemailadressisabhinav_srivatsa6gmailcomandIam19

# \d matches decimal digits 0-9

print(' '.join(re.findall(r'\d',  'I have 3 numbers: 54321, 4748 and 5-98'))) # 3 5 4 3 2 1 4 7 4 8 5 9 8

# \D mathes anything NOT in \d

print(' '.join(re.findall(r'\D',  'I have 3 numbers: 54321, 4748 and 5-98'))) # I   h a v e     n u m b e r s :   ,     a n d   -

# \t matches tab
# \n matches newline
# \r matches return
# \A matches the start of a string (same as ^ in a single line)
# \Z matches the end of a string (same as $ in a single line)

# + checks if one or more of the character used

print(''.join(re.findall(r'[^\s+]', 'tanush     eats    a lot  of big     dinosaurs'))) # tanusheatsalotofbigdinosaurs

