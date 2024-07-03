# Name: Dhanshri Supratkar USN No.: CS22186
# Write a program to check whether the entered number is Armstrong or not.

n = int(input("Enter a number to check if it's an Armstrong number: "))
if n < 0:
    print("Please enter a positive integer.")
else:
    num_digits = len(str(n))
    original = n
    armstrong_sum = 0
    while n > 0:
        digit = n % 10
        armstrong_sum += digit ** num_digits
        n //= 10
    if original == armstrong_sum:
        print(f"{original} is an Armstrong number.")
    else:
        print(f"{original} is not an Armstrong number.")
