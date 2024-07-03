# Name: Dhanshri Supratkar USN No.: CS22186
# Write a program to generate the following pattern:
#         1 
#       1 2
#     1 2 3
#   1 2 3 4
# 1 2 3 4 5

for i in range(1, 6):
    for j in range(6, i+1, -1):
        print(end="  ")
    for k in range(1, i+1):
        print(k, end=" ")
    print()
