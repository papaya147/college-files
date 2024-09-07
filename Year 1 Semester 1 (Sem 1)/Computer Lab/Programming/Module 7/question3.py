import numpy as np

names = np.array(['Mark', 'Sam', 'Henry', 'John', 'Xander', 'Hornato', 'Wade', 'Xenos', 'Barry', 'Rich'])
heights = np.array([145.5, 193.2, 178.4, 135.9, 169.8, 159.3, 178.4, 183.2, 176.7, 165.3])
sort = np.lexsort((names, heights))
for i in sort:
    print(f'{names[i]}, {heights[i]}')