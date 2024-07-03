# Name: Dhanshri Supratkar USN No.: CS22186
# Write a program to generate the following pattern:
# 1 
# 2 3
# 4 5 6
# 7 8 9 10

n = 1
for i in range(1, 5):
    for j in range(1, i+1):
        print(n, end=" ")
        n = n+1
    print()
