# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a program to print the following star pattern using for loop:
#  *
#  *  *
#  *  *  *
#  *  *  *  *
#  *  *  *  *  *
#  *  *  *  *
#  *  *  *
#  *  *
#  *

for i in range(6, -5, -1):
    for j in range(6, abs(i)+1, -1):
        print(" *", end=" ")
    print()
