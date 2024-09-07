def duplicate_characters(sen):
    words = sen.split(' ')
    unique_words = []
    for word in words:
        if word not in unique_words:
            unique_words.append(word)
    word_count = {}
    for unique in sorted(unique_words):
        count = 0
        for word in words:
            if unique == word:
                count += 1
        word_count[unique] = count
    return word_count
        

sen = input()
dict = duplicate_characters(sen)
for i, j in dict.items():
    print(f'{i}:{j}')