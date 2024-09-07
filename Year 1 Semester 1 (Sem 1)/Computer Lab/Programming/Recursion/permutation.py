def permute(n):
    if len(n) == 1:
        return n

    word = ''.join(sorted([i.lower() for i in n]))
    permutations = []

    for i in range(len(word)):
        for j in permute(word[:i] + word[i + 1:]):
            new_word = word[i]
            for k in j:
                new_word += k
            permutations.append(new_word)
    
    return permutations

n = input()
permutations = permute(n)

for i in range(len(permutations)):
    if permutations[i] == n:
        print(f'Same word in ordered permutation: {i + 1}')