# Name: Dhanshri Supratkar  USN No.: CS22186
# Write a program that read the customer number & power consumed and prints the
# amount to be paid by the customer. Note that output should be well formatted.

cnum = int(input("Enter customer number: "))
power = float(input("Enter power consumed in units: "))
if (power <= 100):
    amt = power*1.00
elif (power <= 300):
    amt = 100+(power-100)*1.25
elif (power <= 500):
    amt = 350+(power-300)*1.50
elif (power > 500):
    amt = 650+(power-500)*1.75
else:
    print("Invalid Entry!")
print("---------Electricity Bill---------")
print("Consumer Number: ", cnum)
print("Power Consumed: ", power)
print("Amount to be paid: ", amt)
print("----------------------------------")
