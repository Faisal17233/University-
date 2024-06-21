# Q1---------------------------------------------------------------------------------------
"""I)Cabinets and Boxes are objects that are mostly in cubic shape. Make a program that takes inputs like height, width
and depth from user and then calculate volume of the cube:
volume = height ∗ width ∗ depth
After calculating volume of cube, compare it with following ranges and print the relevant label:"""

# print("Input height, width and depth in order: ")
# height = float(input())
# weight = float(input())
# depth  = float(input())

# volume = height * weight * depth
# print("volume of cube is: ", volume)
#
# if volume < 11:
#     print("extra small")
# elif volume < 26:
#     print("small")
# elif volume < 76:
#     print("medium")
# elif volume < 101:
#     print("large")
# elif volume < 251:
#     print("extra large")
# else:
#     print("extra-extra large")

# Q2------------------------------------------------------------------------------------------

'''(II)In a company ,worker efficiency is determined on the basis of the time required for a worker to complete a 
particular job.If the time taken by the worker is between 2-3 hours then the worker is said to be highly efficient.
If the time required by the worker is between 3-4hours,then the worker is ordered to improve speed.
If the time taken is between 4-5 hours ,the worker is given training to improve his speed ,and if the time taken by the
worker is more than 5 hours ,then the worker haas to leave the company, If the time taken by the worker is input 
through the keyboard,find the efficiency of the worker.'''

# time = int(input("Enter time: "))
#
# if 1 < time < 3:
#     print("the worker is highly efficient")
# elif 2 < time < 4:
#     print("the worker needs to improve speed")
# elif 3 < time < 6:
#     print("the worker should be trained to improve his speed ")
# else:
#     print("the worker has to leave the company")

# Q3--------------------------------------------------------------------------------------------------

'''The program must prompt the user for a username and password.
The program should compare the password given by the user to a known password.
If the password matches, the program should display “Welcome!” If it doesnt match, the program should display 
“I don’t know you.Note: the password should not be case sensitive and it’s value is abc$123 or ABC$123'''

# user = str(input("Enter name: "))
# password = str(input("Enter password: "))
# password = password.upper()
# check = 'ABC$123'
# if password == check:
#     print("Welcome ", user)
# else:
#     print("I don't known you")

# Q4--------------------------------------------------------------------------------------------------------------------

"(iii)	Try the scenario below:"

"1. Make a program that lists the countries in the set"

# li = ['Canada', 'USA', 'Mexico', 'Australia']
#
# for c in li:
#     print(c)

"2. Create a loop that counts from 0 to 100"

# print("Count from 0 to 100")
# for i in range(0, 101):
#     print(i, end=", ")

"3. Make a multiplication table using a loop"

# print("Table of 5")
# for i in range(1, 11):
#     print(f"5 * {i} = {i * 5}")

"4. Output the numbers 1 to 10 backwards using a loop"

# i = 10
# while i > 0:
#     print(i)
#     i -= 1

"5. Create a loop that counts all even numbers to 10"

# for i in range(2, 11, 2):
#     print(i)

"6. Create a loop that sums the numbers from 100 to 200"

# s = 0
# for i in range(100, 201):
#     s += i
# print("Sum is: ", s)

# Q_Task1---------------------------------------------------------------------------------------------------------------

"""Write a program that converts a positive integer into the Roman number system.
The Roman number system has digits I (1), V (5), X (10), L (50), C(100), D(500) and M(1000).
Numbers up to 3999 are formed according to the following rules:
a) As in the decimal system, the thousands, hundreds, tens and ones are expressed separately.
b) The numbers 1 to 9 are expressed as: 1 I 6 VI 2 II 7 VII 3 III 8 VIII4 IV 9 IX 5 V (An I preceding a V or X is
subtracted from the value, and there cannot be more than threeI’s in a row.)
c) Tens and hundreds are done the same way, except that the letters X, L, C, and C, D, Mare used instead of I, V, X
respectively.
Example: Your program should take an input, such as 1978, and convert it to Roman numerals, MCMLXXVIII."""

# number = int(input("enter a no:"))
# m = ["", "M", "MM", "MMM"]
# c = ["", "C", "CC", "CCC", "CD", "D","DC", "DCC", "DCCC", "CM"]
# x = ["", "X", "XX", "XXX", "XL", "L","LX", "LXX", "LXXX", "XC"]
# i = ["", "I", "II", "III", "IV", "V","VI", "VII", "VIII", "IX"]
#
# thousand = m[number // 1000]
# hundred = c[(number % 1000) // 100]
# ten = x[(number % 100) // 10]
# one = i[number % 10]
#
# ans = (thousand + hundred + ten + one)
# print(ans)



# Q_task2---------------------------------------------------------------------------------------------------------------

# height = int(input("Enter height in inches: "))
# weight = int(input("Enter weight in kg: "))
#
# height = height * 0.0254
# bmi = weight / (height * height)
#
# if bmi < 18.5:
#     print("underweight")
# elif 18.5 <= bmi < 25:
#     print("healthy weight")
# elif 25 <= bmi < 30:
#     print("overweight")
# else:
#     print("obesity")

# Q_task3---------------------------------------------------------------------------------------------------------------

"""Write a program to compute quotient and remainder of a number without using division ('/') operator and modulo
('%') operator. Also mention procedure for calculating"""

# up = int(input("Enter dividend: "))
# down = int(input("Enter divisor: "))
# count = 0
# while up >= down:
#     count = count + 1
#     up = up - down
#
# print("Quotient is: ", count)
# print("Remainder is: ", up)
