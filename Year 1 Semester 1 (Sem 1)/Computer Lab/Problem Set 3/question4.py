# Salary_21BDS0340(list List):
# 	Initialise Max_Salary and Min_Salary as the first salary field in List
# 	Initialise Max_Id and Min_Id as the first id field in List
# 	Loop through List as I
# 		If I’s Salary > Max_salary
# 			Max_Salary is now I’s Salary
# 			Max_Id is now I’s Id
# 	Loop through List as I
# 		If I’s Salary < Min_salary
# 			Min_Salary is now I’s Salary
# 			Min_Id is now I’s Id
# 	Display Max_Id
# 	Display Min_Id
# Read List as evaluated input
# Call Salary_21BDS0340(List)

def Salary_21BDS0340(List):
    # initialising min and max salaries and ids
    max_salary = min_salary = List[0]['salary']
    max_id = min_id = List[0]['id']

    # finding max salary
    for i in List:
        if i['salary'] > max_salary:
            max_salary = i['salary']
            max_id = i['id']

    # finding min salary
    for i in List:
        if i['salary'] < min_salary:
            min_salary = i['salary']
            min_id = i['id']

    print(max_id)
    print(min_id)

List = eval(input())
Salary_21BDS0340(List)