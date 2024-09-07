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
