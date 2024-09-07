def translator_21BDS0340(n):
    word = 'anaconda'
    letters = list(word)
    bin_arr = []
    try:
        n = int(n)
        if n < 0 or n > 255:
            return 'Number should be ≤255'
        n = str(bin(n))[2:]
        bin_arr = [n]
    except:
        n = n
        bin_arr = [format(ord(i), 'b') for i in n]
    output = []
    for i in bin_arr:
        index = 7
        for j in range(len(i) - 1, -1, -1):
            if i[j] == '1':
                letters[index] = letters[index].upper()
            index -= 1
        output.append(''.join(letters))
        letters = list(word)
    return output
    
word = input()
output = translator_21BDS0340(word)
if type(output) == list:
    print(' '.join(output))
else:
    print(output)