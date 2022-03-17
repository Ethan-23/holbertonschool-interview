#!/usr/bin/python3
"""NQueens Problem"""

import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
if not str.isdigit(sys.argv[1]):
    print("N must be a number")
    exit(1)
if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)
number = int(sys.argv[1])

boards = []
times = 0
while len(boards) != number - 2:
    ilist = []
    jlist = []
    board = []
    prev = times - 1
    cont = 0
    for i in range(number):
        for j in range(number):
            found = 1
            if i != j and i not in ilist and j not in jlist:
                for k in range(len(boards)):
                    if [i, j] in boards[k]:
                        cont = 1
                    if len(boards) == number - 3:
                        if [j, i] in boards[k]:
                            found = 0
                if cont == 1:
                    cont = 0
                    continue
                if len(boards) == number - 3:
                    if found == 1:
                        continue
                if j == prev + 2 and [j, i] not in board:
                    ilist.append(i)
                    jlist.append(j)
                    prev = j + times
                    board.append([i, j])
                elif prev + 2 > number - 1 and [j, i] not in board:
                    ilist.append(i)
                    jlist.append(j)
                    prev = j + times
                    board.append([i, j])
    print(board)
    boards.append(board)
    times += 1
