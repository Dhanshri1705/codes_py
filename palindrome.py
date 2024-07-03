# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a PYTHON program to check the entered number is palindrome or not.

n = int(input("Enter a positive integer to check if it's a palindrome: "))
if n < 0:
    print("Please enter a positive integer.")
else:
    original = n
    reverse = 0
    while n > 0:
        digit = n % 10
        reverse = reverse * 10 + digit
        n //= 10
    if original == reverse:
        print(f"{original} is a palindrome.")
    else:
        print(f"{original} is not a palindrome.")
