# Check_21BDS0340(String Param):
# 	Initialise String_Length as length of Param
# 	Initialise End_Character as the last character of Param and convert it to integer
# 	Return True if String_Length equals End_Character, else return False
# Read String as input
# Display Check_YourRegistrationNumber(String)


def Check_21BDS0340(Parameter):
    # getting length of Parameter
    string_length = len(Parameter)

    # getting last character of Parameter
    end_character = int(Parameter[-1])

    # return whether they are the same
    return string_length == end_character

string = input()
print(Check_21BDS0340(string))