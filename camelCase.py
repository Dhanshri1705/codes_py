# Name: Dhanshri SUpratkar  USN No.: CS22186
# 6. Convert a String to camelCase in Python.

s = "hello_world"
camel_case = ''.join(word.capitalize() for word in s.split('_'))
print("Original String:", s)
print("Converted String:", camel_case)
