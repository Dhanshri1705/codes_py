# Name: Dhanshri Supratkar USN No.: CS22186
# Write a PYTHON program to print the largest of n numbers.

n = int(input("Enter the number of values: "))
if n <= 0:
    print("Please enter a positive integer for the number of values.")
else:
    l = float('-inf')
    i = 1
    while i <= n:
        value = int(input(f"Enter value {i}: "))
        if value > l:
            l = value
        i += 1
    print(f"The largest number among the {n} values is: {l}")
