farms = int(input("Enter number of farms: "))
litre_sum = 0
milli_sum = 0 
for i in range(farms):
    milk = input(f"Farm {i + 1}: ").split(" ")
    litre_sum += int(milk[0])
    milli_sum += int(milk[1])

# carrying over the extra milliliters to liters
litre_sum += int(milli_sum / 1000)
milli_sum %= 1000
print(f"Total is {litre_sum} liters and {milli_sum} milliliters")