#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun May  9 11:12:05 2021

@author: lucianos
"""

MAX=8

def positionate_queens():
    solution = []
    occupied_columns = [False] * MAX
    positive_diagonals = {}
    negative_diagonals = {}

    # Initializes board
    for i in range(MAX):
        for j in range(MAX):
            positive_diagonals[i + j] = False
            negative_diagonals[i - j] = False

    # Initializes result array
    result = []

    def backtrack(i):
        # If all lines were already covered
        if i == MAX:
            result.append(list(solution))

        # Verifies if position is valid
        for j in range(MAX):
            if not occupied_columns[j] and not positive_diagonals[i + j] and not negative_diagonals[i - j]:
                solution.append(j)
                occupied_columns[j] = positive_diagonals[i + j] = negative_diagonals[i - j] = True

                # Produces new solution branches
                backtrack(i + 1)
                solution.pop()
                occupied_columns[j] = positive_diagonals[i + j] = negative_diagonals[i - j] = False

    backtrack(0)
    
    return result

# Firstly, calculates all positioning solutions
solutions = positionate_queens()

# Reads number of boards in test cases
boards_number = int(input())

# Iterates through all test cases
for bn in range(boards_number):
    board = []

    # Reads board
    for i in range(MAX):
        board.append([int(number) for number in input().split()])

    max_result = 0

    # Verifies, for each solution, which one has the greatest scores sum
    for solution in solutions:
        current_result = sum(board[i][solution[i]] for i in range(MAX))
        max_result = max(max_result, current_result)

    print('%5d' % max_result)