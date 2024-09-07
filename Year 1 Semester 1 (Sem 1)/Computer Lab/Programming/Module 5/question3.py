sen = input().lower()
word = input().lower()
length = len(word)
found = False

for i in range(len(sen)):
    if sen.replace(sen[i:i + length], word) == sen:
        found = True
        print(i)
        print(i + length)
        break

if not found:
    print('Not Found')