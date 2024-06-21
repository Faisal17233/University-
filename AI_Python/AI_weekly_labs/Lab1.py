# Q1-----------------------------------------------------------------------
# Try out some of the string functions listed in dir (ignore those with underscores '_'
# around the method name).

##s = "finalized"
##print(s.upper())
##print(s.count("a"))
##print(s.split())
##print(s.find("n"))
##print(s.capitalize())
##print(s.replace("n", "e"))
##print(s.index("z"))


# Q2-----------------------------------------------------------------------
# (i)Write a python program to swap 4 variables values (input 4 values.)

##a,b,c,d=input(),input(),input(),input()
##t=a
##a=d
##d=t
##t=b
##b=c
##c=t
##print(a,b,c,d)

# Q3---------------------------------------------------
# (ii) Write a Python program to convert temperatuer to and from celsius

##print('press 1 to convert Celsius to Fahrenheit, press 2 to convert Fahrenheit to Celsius')
##a=int(input())
##
##if a==1:
##    c=int(input())
##    f=c*(9/5)+32
##    print(f)
##elif a==2:
##    f=int(input())
##    c=(f-32)*5/9
##    print(c)

# Q4---------------------------------------------------------------------

# (i) Play with some of the list functions. You can find the methods you can call on an
# object via the dir and get information about them via the help command.

##s = [1,2,3,4,5]
##s.append(13)
##print(s)
##s.pop()
##print(s)
##print(s.count(3))
##s.reverse()
##print(s)
##s.sort()
##print(s)


# Q5----------------------------------------------------
# (ii) Write a python program to count the number of strings where the
#     length is 2 or more and first and last character are same from list

##s=['abc34', 'xyz', 'aba', '1221','ss','fabc']
##c=0
##s=['abc34', 'xyz', 'aba', '1221','ss','fabc']
##for i in s:
##    if len(i)>1 and i[0]==i[-1]:
##        c+=1
##
##print(c)

# Q6-------------------------------------------------------
# (ii) Write a Python script to concatenate following dictionaries
# to create a new one

##dict1={1:10, 2:20}
##dict2={3:30, 4:40}
##dict3={5:50,6:60}
##result=dict1 | dict2 | dict3
##print(result)

# Q7---------------------------------------------------------
# (i)Write a list comprehension which, from a list, generates a lowercased
#   version of each string that has length greater than five

##s= ['Red', 'Green', 'White', 'Black', 'Pink', 'YEllow','Teapink']
##
##for i in s:
##    if len(i)>5:
##        z=i.lower()
##        a=s.index(i)
##        s[a]=z
##print(s)

# Q8----------------------------------------------------------
# (ii) Write a Python program to print a specified list after removing
#     the 0th, 4th and 5th elements.

##s=['Red', 'Green', 'White', 'Black', 'Pink', 'Yellow','Teapink']
##s.remove(s[5])
##s.remove(s[4])
##s.remove(s[0])
##print(s)

# Q9----------------------------------------------------------
# p1

##x = 6
##if (type(x) is int):
## print ("true")
##else:
## print ("false")

# p2
##x=6
##if (type(x)): x = 7.2
##if (type(x) is not int):
## print ("true")
##else:
## print ("false")

# p3

##list1=[1,2,3,4,5]
##list2=[6,7,8,9]
##for item in list1:
## if item in list2:
##  print("overlapping")
## else:
##  print("not overlapping")

# p4

##a=10
##a//=3
##print("floor divide=",a)
##a**=5
##print("exponent=",a)

# p5

##a = 60
##b = 13
##c = 0
##c = a & b
##print("Line 1", c )
##c = a | b
##print("Line 2 ", c )
##c = a ^ b
##print("Line 3 ", c )
##c = ~a
##print("Line 4", c )
##c = a << 2
##print("Line 5 ", c )
##c = a >> 2
##print("Line 6 -", c )


#Q Taskq
# Create a python Program that perform following tasks for any problem of your choice
# Task1: Introduction
print("Welcome to BookShop")
print("Here you can get all your books easily from home")

# Task2: Terminal
print("Write 'Python Q_task.py' in terminal to run this program")

# Task3: Python interpreter
print("Write each individual line in interpreter to run this program")

# Task5: Text Editor
print("Write the code in the text editor, save it with extension '.py' and then you can run it\n")

# Task7: List and tuple
Booklist = ["The Great Gatsby", "Pride and Prejudice", "A song of ice and fire", "To kill a Mockingbird", "The Catcher in the Rye", "Wuthering Heights", "Anna Karenina\t", "Rich Dad Poor Dad",
            "Great Expectations", "War and Peace\t"]
Pricetuple = (15.99, 14.56, 18.78, 12.23, 14.99, 17.69, 19.99, 14.99, 18.12, 16.0)

# Task9: For Loop
print("No.\tBOOKS\t\t\t\tPrice")

for i in range(0, 10):
    print(f"{i}\t{Booklist[i]}\t\t{Pricetuple[i]}$")


# Task4: Variables
# Task6: Function
# Task8: Conditional Statment
# Task10: User input and the while loop

def BookPurchase(Pricetuple, Booklist):
    print("press the number corresponding to the book to add it to your cart\nPress q to exit")
    total = 0
    a = input()
    while True:
        if a == 'q':
            break
        elif a.isdecimal() and int(a) < 10:
            total = total + Pricetuple[int(a)]
            print(Booklist[int(a)], "is added to your cart")
        else:
            print("Wrong Input, please try again")
        a = input()

    print("Your total is: ", total, "$")


BookPurchase(Pricetuple, Booklist)
