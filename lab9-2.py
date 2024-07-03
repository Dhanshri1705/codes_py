str1 = "Welcome to CSE Department."
d = a = s = 0
for i in str1:
    if(i.isspace()):
        s+=1
    if(i.isalpha()):
        a+=1
    if(i.isdigit()):
        d+=1
print("Digits : ",d)
print("Alphabets : ",a)
print("Spaces : ",s)
print(str1.split())
print(str1.partition('o'))
str2 = "    anaconda    "
print(str2)
print(len(str2))
print(str2.lstrip())
print(len(str2.lstrip()))
print(str2.rstrip())
print(len(str2.rstrip()))
print(str2.strip())
print(len(str2.strip()))
print(str1.replace(".",""))