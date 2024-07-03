# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a program to find the area of circle, circumference of circle,  
# volume of cube, volume of cone.

radius_circle = float(input("Enter the radius of the circle: "))
area = 3.14 * radius_circle**2
circumference = 2 * 3.14 * radius_circle

side_cube = float(input("Enter the side length of the cube: "))
volume_cube = side_cube**3

radius_cone = float(input("Enter the radius of the cone: "))
height_cone = float(input("Enter the height of the cone: "))
volume_cone = (1/3) * 3.14 * radius_cone**2 * height_cone

print(f"\nArea of the circle: {area}")
print(f"Circumference of the circle: {circumference}")
print(f"\nVolume of the cube: {volume_cube}")
print(f"\nVolume of the cone: {volume_cone}")
