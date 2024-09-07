base_salary = float(input())
dearness_allowance = base_salary * 0.8
house_rent_allowance = base_salary * 0.3
deduction = base_salary * 0.12

final_salary = base_salary + dearness_allowance + house_rent_allowance - deduction
print(final_salary)