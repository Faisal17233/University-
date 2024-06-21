# Ex Lambda---------------------------------------------------
# z = lambda a, b, c, d: a * b + (c / d)
# print(z(2, 4, 2, 5))
#
# Ex array------------------------------------------------------
#
# arr = ["f", "a", "i", "s"]
# arr[0] = "k"
#
# Ex mymodule-------------------------------------------------------
# import mymodule
#
# mymodule.add(2, 5)


#Ex 1.1-----------------------------------------------------------------------------------------
"""a Python program to square and cube every number in a given list of integers using Lambda."""
# list1 = [2,3,4,5,6,7,8,9]
# for i in list1:
#     x=lambda a:a**2
#     y=lambda a:a**3
#     print(x(i))
#     print(y(i))

#Ex 1.2-------------------------------------------------------------------------------------------

"""II. a Python program to find if a given string starts with a
given character using Lambda."""

# x = lambda s, c: True if (s[0]==c) else False
#
# string = "sabeeh hassan"
# char = input("Enter Character: ")
#
# print(x(string, char))

#Ex 1.3-----------------------------------------------------------------------------------------------
"III. a Python program to extract year, month, date and time using Lambda"

# from datetime import datetime
#
# temp = datetime.now()
#
# year = lambda x: x.year
#
# month = lambda x: x.month
#
# date = lambda x: x.date()
#
# time = lambda x: x.time()
#
# print(f"Date: {date(temp)}, Month: {month(temp)}, Year: {year(temp)}, Time: {time(temp)}")

#Ex2.1"

""" I. You have collected information about cities in your province. You
decide to store each city's name, population, and mayor in a file. Write
a python program to accept the data for a number of cities from the 
keyboard and store the data in a file in the order in which they're entered."""

# num = int(input("Enter number of cities: "))
# print()
#
# file = open("cities.txt", 'w')
#
# for i in range(num):
#     name = input(f"Enter the name of city {i+1}: ")
#     population = input(f"Enter the population of the city {i+1}: ")
#     mayor = input(f"Enter the name of mayor of the city {i+1}: ")
#     print()
#
#     file.write(f"{name}, {population}, {mayor}\n")
#
# file.close()

#Ex2.2-------------------------------------------------------------------------------------
"""II. Write a python program to create a data file student.txt
and append the message “Now we are AI students"""

# file = open("message.txt", 'a')
#
# file.write("Now we are AI students\n")
# file.close()

#Ex 3---------------------------------------------------------------------------------------
import time
s=time.time()
print(s)
print(time.ctime(s))
time.sleep(5)
print("5 second delay")

import glob
print(glob.glob("C:/Users/Faisal Khan/PycharmProjects/AI_weekly_labs/*.py"))

import random
print(random.randint(1,100))
print(random.random())

x=[1,2,3,4,5,6,7,8,9]
random.shuffle(x)
print(x)
print(random.sample(x,3))