def successors(state):
    # Generate successor states
    moves = []
    missionaries_startpos, cannibals_startpos, boat = state
    possible_moves = [(1, 0), (2, 0), (0, 1), (0, 2), (1, 1)]
    for move in possible_moves:
        if boat == 1:
            new_state = (missionaries_startpos - move[0], cannibals_startpos - move[1], 0)
        else:
            new_state = (missionaries_startpos + move[0], cannibals_startpos + move[1], 1)
        if 0 <= new_state[0] <= 3 and 0 <= new_state[1] <= 3:
            missionaries_des = 3 - new_state[0]
            cannibals_des = 3 - new_state[1]
            # if cannibals dont outnumber missionaries on both sides
            if not 0 < new_state[0] < new_state[1] and not 0 < missionaries_des < cannibals_des:
                moves.append(new_state)
    return moves


def Iterative_deepening_search(state, depth, max_depth, path, visited):
    # Recursive depth-first search
    if depth > max_depth:
        return None
    visited.add(state)
    path.append(state)
    if state == (0, 0, 0):  # if goal state is reached
        return path
    for i in successors(state):
        if i not in visited:
            result = Iterative_deepening_search(i, depth + 1, max_depth, path, visited)
            if result:
                return result
    path.pop()
    return None


def Max_depth_setter(initial_state):
    # Iterative deepening search
    max_depth = 0
    while True:
        visited = set()
        path = []
        result = Iterative_deepening_search(initial_state, 0, max_depth, path, visited)
        if result:
            return result
        max_depth += 1



initial_state = (3, 3, 1)

paths = Max_depth_setter(initial_state)
if paths:
    print("Solution found:")
    for state in paths:
        print(state)
else:
    print("No solution found")
