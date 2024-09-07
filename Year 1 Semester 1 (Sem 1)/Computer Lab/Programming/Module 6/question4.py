questions = open('Questions.txt', 'r')
answers = open('Answers.txt', 'r')
print(questions.read())
user_ans = input().split(' ')
i = 0
sum = 0
for line in answers.readlines():
    if user_ans[i] == line.strip()[-1].lower():
        sum += 50
    i += 1
print(sum)