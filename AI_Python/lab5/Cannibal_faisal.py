def is_valid_state(state):
    # Check if a state is valid (cannibals do not outnumber missionaries)
    missionaries_left, cannibals_left, boat = state
    missionaries_right = 3 - missionaries_left
    cannibals_right = 3 - cannibals_left
    if missionaries_left > 0 and missionaries_left < cannibals_left:
        return False
    if missionaries_right > 0 and missionaries_right < cannibals_right:
        return False
    return True

def goal_test(state):
    # Check if all missionaries and cannibals are on the other side
    return state == (0, 0, 0)

def successors(state):
    # Generate successor states
    moves = []
    missionaries, cannibals, boat = state
    possible_moves = [(1, 0), (2, 0), (0, 1), (0, 2), (1, 1)]
    for move in possible_moves:
        if boat == 1:
            new_state = (missionaries - move[0], cannibals - move[1], 0)
        else:
            new_state = (missionaries + move[0], cannibals + move[1], 1)
        if 0 <= new_state[0] <= 3 and 0 <= new_state[1] <= 3 and is_valid_state(new_state):
            moves.append(new_state)
    return moves

def dfs_recursive(state, depth, max_depth, path, visited):
    # Recursive depth-first search
    if depth > max_depth:
        return None
    visited.add(state)
    path.append(state)
    if goal_test(state):
        return path
    for succ in successors(state):
        if succ not in visited:
            result = dfs_recursive(succ, depth + 1, max_depth, path, visited)
            if result:
                return result
    path.pop()
    return None

def iterative_deepening_search(start_state):
    # Iterative deepening search
    max_depth = 0
    while True:
        visited = set()
        path = []
        result = dfs_recursive(start_state, 0, max_depth, path, visited)
        if result:
            return result
        max_depth += 1

# Initial state
start_state = (3, 3, 1)

# Perform IDS
solution = iterative_deepening_search(start_state)
if solution:
    print("Solution found:")
    for state in solution:
        print(state)
else:
    print("No solution found")