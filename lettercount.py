# Name: Dhanshri Supratkar  USN No.: CS22186
# 10. Python program to input a string and find total number of letters and digits

s = input("Enter a string: ")
a = d = 0
for i in s:
    if (i.isalpha()):
        a += 1
    if (i.isdigit()):
        d += 1
print("Number of Letters: ", a)
print("Number of Digits: ", d)
