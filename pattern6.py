# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a program to generate the following pattern:
#          *
#        * * *
#      * * * * *
#    * * * * * * *
#  * * * * * * * * *

l = r = 5
for i in range(1, 6):
    for j in range(1, 11):
        if j >= l and j <= r:
            print(" *", end="")
        else:
            print(end="  ")
    l = l - 1
    r = r + 1
    print()
