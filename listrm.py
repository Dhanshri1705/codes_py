# Name: Dhanshri Supratkar   USN: CS22186
#write a program to print the list after removing the 0th, 2nd, 4th,6th index numbers in [12,24,35,70,88,120,155].


my_list = [12, 24, 35, 70, 88, 120, 155]
result = [my_list[i] for i in range(len(my_list)) if i not in [0, 2, 4, 6]]
print("List after removing elements at specified indices:", result)
