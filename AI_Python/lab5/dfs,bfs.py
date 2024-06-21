from queue import Queue
import random

dictionnary = {'a': ['a', 'c'], 'b': ['a', 'c', 'd'], 'c': ['a', 'b'], 'd': ['f'], 'f': ['b']}
check = 0


def InsertNode():
    a = input("enter name of node: ")
    temp = {}
    temp[a] = []
    dictionnary.update(temp)


def InsertVertex():
    node = input("enter 1 connection: ")
    vertex = input("enter 2 connection: ")
    save = list(dictionnary.keys())
    d = 0
    for i in save:
        if i == vertex:
            d += 1
        if i == node:
            d += 1

    if d == 2:
        dictionnary[node].append(vertex)
    else:
        print("wrong input")


def dfs(node, visited, find):
    keys = list(dictionnary.keys())
    if find not in keys:
        print("node does not exists")
        return
    global check
    check = 0
    if node == find:
        print("path exists")
        check = 1
        return
    visited[node] = 1
    if not dictionnary[node]:
        return

    for i in dictionnary[node]:
        if visited[i] == 0:
            dfs(i, visited, find)


#queue = []


def bfs(node, visited, find):
    q = Queue(maxsize=0)
    keys = list(dictionnary.keys())
    if find not in keys:
        print("node does not exists")
        return
    global check
    check = 0
    visited[node] = 1
    q.put(node)

    while not q.empty():
        m = q.get()
        # print(m, end=" ")

        for value in dictionnary[m]:

            if visited[i] == 0:
                if value == find:
                    print("path exists")
                    check = 1
                    return
                visited[value] = 1
                q.put(value)
            if not dictionnary[value]:
                return


def search_with_closed_list(start, goal):
    visited = set()
    frontier = [start]
    while frontier:
        node = frontier.pop(0)
        if node == goal:
            print("Path exists")
            return
        if node not in visited:
            visited.add(node)
            frontier.extend(dictionnary[node])
    print("Path does not exist")


def search_with_open_list(start, goal):
    visited = set()
    frontier = [start]
    while frontier:
        node = frontier.pop()
        if node == goal:
            print("Path exists")
            return
        if node not in visited:
            visited.add(node)
            frontier.extend(dictionnary[node])
    print("Path does not exist")


def randomseacrh(node, find, keys):
    if find not in keys:
        print("node does not exists")
        return
    global check
    check = 0
    if node == find:
        print("path exists")
        check = 1
        return
    if not dictionnary[node]:
        return
    currentnode = dictionnary[node]
    ran = random.choice(currentnode)
    randomseacrh(ran, find, keys)


if '__main__' == __name__:
    ui = 0
    while ui != 7:
        ui = int(input("\nEnter 1 to Insert Node\nEnter 2 to Insert vertex\nEnter 3 to print\nEnter 4 to Breadth First Search\nEnter 5 to Random Search\nEnter 6 to Depth First Search\nEnter 7 to search with closed list\nEnter 8 to search with open list\nEnter 9 to exit\n\nEnter Number: "))

        if ui == 1:
            InsertNode()

        elif ui == 2:
            InsertVertex()

        elif ui == 3:
            print(dictionnary)


        elif ui == 4:
            find = input("enter the node to find: ")
            keys = list(dictionnary.keys())
            visited = {}
            for i in keys:
                tdict = {}
                tdict[i] = 0
                visited.update(tdict)
            bfs(keys[0], visited, find)
            if check == 0:
                print("path does not exists")

        elif ui == 5:
            find = input("enter the node to find: ")
            keys = list(dictionnary.keys())
            randomseacrh(keys[0], find, keys)
            if check == 0:
                print('path does not exists')

        elif ui == 6:
            t = 0
            find = input("enter the node to find: ")
            keys = list(dictionnary.keys())
            visited = {}
            for i in keys:
                tdict = {}
                tdict[i] = 0
                visited.update(tdict)
            dfs(keys[0], visited, find)
            if check == 0:
                print("path does not exists")

        elif ui == 7:
            start = input("Enter start node: ")
            goal = input("Enter goal node: ")
            search_with_closed_list(start, goal)

        elif ui == 8:
            start = input("Enter start node: ")
            goal = input("Enter goal node: ")
            search_with_open_list(start, goal)
