word = input().lower()
letters = list(word)
verdict = 'GOOD'

for i in range(len(letters)):
    letter1 = letters[i]
    for letter2 in letters[i + 1:]:
        if letter1 == letter2:
            verdict = 'BAD'
            break
            
print(verdict)