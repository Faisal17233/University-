import datetime
import time
temp = datetime.datetime.now()
a = temp.second
while True:
    temp = datetime.datetime.now()
    if temp.second != a:
        a = temp.second
        print(temp.second)
