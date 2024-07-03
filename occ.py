# Name: Dhanshri Supratkar   USN: CS22186
#Write a program to count the occurrences of each element in a list.


my_list = [11, 22, 33, 11, 44, 55, 22, 99]
element_counts = {}
for element in my_list:
    if element in element_counts:
        element_counts[element] += 1
    else:
        element_counts[element] = 1
for element in element_counts:
    print("Element", element, "occurs", element_counts[element], "times.")
