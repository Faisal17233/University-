from itertools import permutations
import numpy

def Path_find(graph, start):
    # Generating all possible paths except for the starting city
    cities = set(range(1, len(graph) + 1))
    cities.remove(start)
    all_combinations = list(permutations(cities))
    print(all_combinations)
    # Initialize minimum cost and the best permutation
    min_cost = float('inf')
    best_permutation = None

    # Calculate cost of each path
    for i in all_combinations:
        cost = 0
        current_city = start

        for city in i:
            cost += graph[current_city - 1][city - 1]
            current_city = city

        # Add the cost of returning to the starting city
        cost += graph[current_city - 1][start - 1]

        if cost < min_cost:
            min_cost = cost
            #saving the path of this cost
            best_permutation = [start]
            for m in i:
                best_permutation.append(m)
            best_permutation.append(start)

    return best_permutation, min_cost


if __name__ == '__main__':
    #graph[i][j] is the cost of the edge between city i and city j.

    a = int(input("Enter number of cites: "))
    graph = numpy.ndarray([a,a])
    v = set()

    for i in range(a):
        for j in range(a):
            if i==j:
                graph[i][j]=0
                continue
            if (i,j) in v:
                continue
            v.add((j,i))
            w=int(input(f"Enter the cost between city {i+1} and city{j+1}: "))
            graph[i][j]= w
            graph[j][i] = w

    print(graph)
    path, cost = Path_find(graph, 1)
    print(f"Tour route: {path}")
    print(f"Total cost: {cost}")