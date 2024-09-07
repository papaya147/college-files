from itertools import permutations
import itertools
import pandas as pd

df = pd.read_csv('words.txt', delimiter = '\n')
print(df)
n = input().strip()
letters = list(n)
permutation = list(itertools.permutations(letters))
for i in permutation:
    i = ''.join(i)
    if len(df[df['words'] == n]) > 0:
        print(i)