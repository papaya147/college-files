import pandas as pd

df = pd.read_csv('words.txt', delimiter = '\n')

def search(n):
    return len(df[df['words'] == n]) > 0