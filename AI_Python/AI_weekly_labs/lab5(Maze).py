from queue import Queue


def dfs(maze):
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    start_pos = None
    for i in range(len(maze)):
        for j in range(len(maze[0])):
            if maze[i][j] == 'S':
                start_pos = (i, j)
                break
        if start_pos:
            break
    stack = [(start_pos, [start_pos])]
    visited = set()
    while stack:
        current_pos, path = stack.pop()
        if maze[current_pos[0]][current_pos[1]] == 'E':
            return path
        visited.add(current_pos)
        for direction in directions:
            new_i = current_pos[0] + direction[0]
            new_j = current_pos[1] + direction[1]

            new_child = (new_i, new_j)
            if 0 <= new_i < len(maze) and 0 <= new_j < len(maze[0]) and maze[new_i][new_j] != '#' and new_child not in visited:
                stack.append((new_child, path + [new_child]))
    return None


def bfs(maze):
    q1 = Queue(maxsize=0)
    # Implementation of Breadth-First Search
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    start_pos = None
    for i in range(len(maze)):          # searching the starting point
        for j in range(len(maze[0])):
            if maze[i][j] == 'S':
                start_pos = (i, j)
                break
        if start_pos:
            break

    q1.put((start_pos, [start_pos]))
    visited = set()
    while not q1.empty():
        current_pos, path = q1.get()
        if maze[current_pos[0]][current_pos[1]] == 'E':
            return path
        visited.add(current_pos)
        for direction in directions:
            new_i = current_pos[0] + direction[0]
            new_j = current_pos[1] + direction[1]
            neighbor = (new_i, new_j)
            if 0 <= new_i < len(maze) and 0 <= new_j < len(maze[0]) and maze[new_i][new_j] != '#' and neighbor not in visited:
                q1.put((neighbor, path + [neighbor]))
                visited.add(neighbor)
    return None


maze = [
    ['#', '.', '.', '#', '#', '#', '#', '#', '#'],
    ['#', '.', '.', '.', '.', '#', '.', 'E', '#'],
    ['#', '.', '.', '#', '.', '#', '.', '#', '#'],
    ['#', '.', '.', '.', '.', '.', '.', '.', '#'],
    ['#', '#', '.', '#', '#', '#', '#', '#', '#'],
    ['#', '#', '.', '#', '#', '#', '#', '.', '#'],
    ['#', '#', '.', '.', '.', '.', '#', '.', '#'],
    ['#', 'S', '.', '#', '#', '#', '#', '.', '#'],
    ['#', '.', '.', '.', '#', '#', '#', '#', '#']
]

# DFS
dfs_path = dfs(maze)
if dfs_path:
    print("DFS Path found:")
    for position in dfs_path:
        print(position)
else:
    print("No DFS path found")

# BFS
bfs_path = bfs(maze)
if bfs_path:
    print("\nBFS Path found:")
    for position in bfs_path:
        print(position)
else:
    print("\nNo BFS path found")
