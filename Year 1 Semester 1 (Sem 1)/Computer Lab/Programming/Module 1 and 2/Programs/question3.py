number = int(input("Enter number: "))
roman = ""

tens = number // 10
units = number % 10

if tens > 0 and tens < 4:
    roman += (tens * 'X')
elif number / 10 == 4:
    roman += 'XL'
elif tens > 4 and tens < 9:
    roman += 'L' + ((tens - 5) * 'X')
elif tens == 9:
    roman += 'XC'
elif tens == 10:
    roman += 'C'

if units > 0 and units < 4:
    roman += (units * 'I')
elif units == 4:
    roman += 'IV'
elif units > 4 and units < 9:
    roman += 'V' + ((units - 5) * 'I')
elif units == 9:
    roman += 'IX'

print(f"{number} in Roman numerals is {roman}")
