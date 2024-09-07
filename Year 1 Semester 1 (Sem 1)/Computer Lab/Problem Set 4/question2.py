import pandas as pd

def score_mapper(score):
    if score >= 90:
        return 'A'
    if score >= 80:
        return 'B'
    if score >= 60:
        return 'C'
    else:
        return 'F'

inp1 = eval(input())
inp2 = eval(input())
scores = {
    'Mark-1': inp1,
    'Mark-2': inp2
}
indices = ['Maths', 'Eng', 'Cs', 'Phy', 'Che', 'Bio']
scores_df = pd.DataFrame(scores, index = indices)
grade_df = scores_df.applymap(score_mapper)
print(grade_df)