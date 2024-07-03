# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a program to generate the following pattern:
# 5 5 5 5 5 
# 4 4 4 4
# 3 3 3
# 2 2
# 1

n = 5
for i in range(1, 6):
    for j in range(i, 6):
        print(n, end=" ")
    n = n - 1
    print()
