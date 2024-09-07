people = int(input())
days = int(input())
breakfast = int(input())
sum = 0

if people < 0 or days < 0 or breakfast < 0:
    print("Enter Only Positive Value Please!")
else:
    if people % 2 == 0:
        sum = people * 4000 / 2
    else:
        sum = people * 4000 // 2 + 3000
    
    if breakfast == 1:
        sum += 500
    
    print(sum * days)