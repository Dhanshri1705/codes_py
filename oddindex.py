# Name: Dhanshri Supratkar  USN No.: CS22186
# Use a loop to display elements from a given  
# list present at odd index positions.

elements = [1, 2, 3, 4, 5, 6]
print("\nElements at odd index positions:")
for i in range(1, len(elements), 2):
    print(elements[i], end=" ")
