# Name: Dhanshri SUpratkar USN No.: CS22186
# Write a PYTHON program find a factorial of given number.

n = int(input("Enter a non-negative integer to find its factorial: "))
if n < 0:
    print("Factorial is not defined for negative numbers.")
elif n == 0:
    print("The factorial of 0 is 1.")
else:
    f, i = 1, 1
    while i <= n:
        f *= i
        i += 1
    print(f"The factorial of {n} is {f}")
