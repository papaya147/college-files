num = int(input("Enter number: "))
base = int(input("Enter base: "))

new_num = ""
while num != 0:
    new_num += str(num % base)
    num = num // base
print(new_num[::-1])