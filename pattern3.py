# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a program to generate the following pattern:
# 1 1 1 1 1 
# 2 2 2 2
# 3 3 3
# 4 4
# 5

n = 1
for i in range(1, 6):
    for j in range(i, 6):
        print(n, end=" ")
    n = n + 1
    print()
