# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a program to generate the following pattern:
# *
# **
# ***
# ****
# *****

for i in range(1, 6):
    for j in range(1, i+1):
        print("*", end="  ")
    print()
