#!/usr/bin/python3
"""NQueens Problem"""

import sys


def printSolution(board):
    """printSolution"""
    result = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 1:
                result.append([i, j])
    print(result)


def isSafe(board, row, col):
    """isSafe"""
    for i in range(row):
        if board[i][col] == 1:
            return False

    (i, j) = (row, col)
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j - 1

    (i, j) = (row, col)
    while i >= 0 and j < len(board):
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j + 1
    return True


def nQueen(board, row):
    """nQueen"""
    if row == len(board):
        printSolution(board)
        return
    for i in range(len(board)):
        if isSafe(board, row, i):
            board[row][i] = 1
            nQueen(board, row + 1)
            board[row][i] = 0


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
if not str.isdigit(sys.argv[1]):
    print("N must be a number")
    exit(1)
if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)
n = int(sys.argv[1])

board = [[0 for x in range(n)] for y in range(n)]
nQueen(board, 0)
