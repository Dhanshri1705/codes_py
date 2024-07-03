# Name: Dhanshri Supratkar  USN No.: CS22186
# Print list in reverse order using a loop.

numbers = [1, 2, 3, 4, 5, 6]
print("\nList in reverse order:")
for i in range(len(numbers) - 1, -1, -1):
    print(numbers[i], end=" ")
