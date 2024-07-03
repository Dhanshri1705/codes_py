# Name: Dhanshri SUpratkar  USN No.: CS22186
# Write a PYTHON program to print Fibonacci series up to n
# Display Fibonacci series up to 10 terms.

n = int(input("Enter the number of terms in Fibonacci series: "))
if n <= 0:
    print("Please enter a positive integer.")
else:
    i, first, second = 0, 0, 1
    print(f"Fibonacci series up to {n}:")
    while i <= n:
        print(first, end=" ")
        next = first + second
        first, second = second, next
        i += 1
