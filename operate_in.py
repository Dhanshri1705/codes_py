# Name: Dhanshri Supratkar  USN No.: CS22186
# 8. Check if a substring presents in a string using 'in' operator.

s = input("Enter a string: ")
sub = input("Enter a substring you want to see if it is present or not: ")
if (sub in s):
    print(sub, " is present in the string.")
else:
    print(sub, " is not present in the string.")
