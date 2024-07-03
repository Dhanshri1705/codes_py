# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a python program to find largest number among three numbers.

num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))
num3 = int(input("Enter the third number: "))
if num1 >= num2 and num1 >= num3:
    print(num1, " is the largest.")
elif num2 >= num1 and num2 >= num3:
    print(num2, " is the largest.")
else:
    print(num3, " is the largest.")
