# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a PYTHON program to print sum of odd numbers up to n.

n = int(input("Enter the value of n: "))
if n <= 0:
    print("Please enter a positive integer.")
else:
    sum, i = 0, 1
    while i <= n:
        sum = sum + i
        i += 2
    print(f"Sum of Odd numbers up to {n}:", sum)
