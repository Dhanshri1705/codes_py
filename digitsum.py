# Name: Dhanshri SUppratkar  USN No.: CS22186
# Write a PYTHON program to find the sum of digits of given number.

n = int(input("Enter a positive integer: "))
if n <= 0:
    print("Please enter a positive integer.")
else:
    summ = 0
    while n > 0:
        digit = n % 10
        summ += digit
        n //= 10
    print(f"The sum of digits is: {summ}")
