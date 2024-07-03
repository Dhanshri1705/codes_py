# Name:Dhanshri Supratkar USN No.: CS22186
# 9. Python program to input a string and find total number uppercase and lowercase letters.

s = input("Enter a string: ")
u = l = 0
for i in s:
    if (i.isupper()):
        u += 1
    if (i.islower()):
        l += 1
print("Number of uppercase characters: ", u)
print("Number of lowercase characters: ", l)
