# Name: Dhanshri Supratkar USN No.: CS22186
# Write a PYTHON program to print the multiplication table.
# Write a program to print a multiplication table of the entered number.

n = int(input("Enter a number for the multiplication table: "))
if n <= 0:
    print("Please enter a positive integer.")
else:
    print(f"\nMultiplication table for {n}:\n")
    i = 1
    while i <= 10:
        print(f"{n} x {i} = ", n * i)
        i += 1
