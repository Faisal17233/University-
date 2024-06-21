from copy import deepcopy


def solveNQueens(n):
    # to check which columns already have queen
    columns = set()
    # to check which diagonals already have queen
    posDiagonals = set()
    negDiagonals = set()

    all_solutions = []  # contains all possible solutions

    # initializing nxn board
    # 0: no queen
    # 1: queen
    board = [[0] * n for i in range(n)]

    def backtrack(row):
        # base condition: if all rows have been iterated
        if row == n:
            # add the copy of final board in 'all_solutions'
            all_solutions.append(deepcopy(board))
            return

        # iterate each column
        for column in range(n):
            # check if it is safe to place the queen or not
            if column in columns or \
                    (row + column) in posDiagonals or \
                    (row - column) in negDiagonals:
                continue  # not safe

            # safe
            columns.add(column)
            posDiagonals.add(row + column)
            negDiagonals.add(row - column)
            board[row][column] = 1  # queen placed

            backtrack(row + 1)  # iterate next row

            # remove the values for next solution
            columns.remove(column)
            posDiagonals.remove(row + column)
            negDiagonals.remove(row - column)
            board[row][column] = 0

    # start with row: 0
    backtrack(0)

    return all_solutions


if __name__ == '__main__':

    num_of_queens = int(input("Enter number of queens (N>3): "))
    result = solveNQueens(num_of_queens)

    print(f"Number of Solutions: {len(result)}\n")

    for i, sol in enumerate(result):
        print(f"Solution {i + 1}:")
        print("-----------------------\n")
        for j in sol:
            print(j)
        print('\n')
