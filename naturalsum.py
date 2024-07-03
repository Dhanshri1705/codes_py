# Name:Dhanshri Supratkar  USN No.: CS22186
# Write a PYTHON program to print sum of natural numbers up to n.
# Calculate the sum of all numbers from 1 to a given number.

n = int(input("Enter the value of n: "))
if n <= 0:
    print("Please enter a positive integer.")
else:
    sum, i = 0, 1
    while i <= n:
        sum = sum + i
        i += 1
    print(f"Sum of Natural numbers up to {n}:", sum)
