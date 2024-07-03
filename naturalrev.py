# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a PYTHON program to print natural numbers up to n in reverse order.

n = int(input("Enter the value of n: "))
if n <= 0:
    print("Please enter a positive integer.")
else:
    print(f"Natural numbers up to {n} in reverse order:")
    i = n
    while i > 0:
        print(i, end=" ")
        i -= 1
