# Name: Dhanshri SUpratkar  USN No.: CS22186
# Write a program to take a number as input and give it in reverse order as output.
# Write a PYTHON program to reverse the given number.
# Reverse a given integer number.

n = int(input("Enter a number: "))
rev = 0
rem = n
while rem > 0:
    digit = rem % 10
    rev = rev * 10 + digit
    rem = rem // 10
print(f"The reverse of {n} is: {rev}")
