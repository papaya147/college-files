def combine(n, m):
    if m == 1:
        return list(n)

    word = ''.join(sorted([i.lower() for i in n]))
    combinations = []

    for i in range(len(word)):
        for j in combine(word[i + 1:], m - 1):
            new_word = word[i] + j
            combinations.append(new_word)
    
    return combinations

n = input()
m = int(input())
combinations = combine(n, m)

for i in combinations:
    print(i)