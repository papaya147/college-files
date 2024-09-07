#taking farenheit as input
far = float(input())

#converting to celcius
cel = lambda x: (x - 32) * (5 / 9)

#displaying
print(format(cel(far), ".2f"))