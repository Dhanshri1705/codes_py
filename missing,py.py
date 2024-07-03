# Name: Dhanshri Supratkar   USN: CS22186
#Write a Python program to find the missing numbers in a list of continuous numbers.


numbers = [1, 2, 3, 5, 7, 8, 10]
min_num = min(numbers)
max_num = max(numbers)
complete_list = list(range(min_num, max_num + 1))
missing_numbers = [num for num in complete_list if num not in numbers]
print("Missing numbers:", missing_numbers)
