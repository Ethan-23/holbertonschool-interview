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
counter = 0
allspots = []
checkspots = []
prev = -1

while len(allspots) < number - 2:
    cols = []
    rows = []
    spots = []
    for col in range(number):
        for row in range(number):
            if col == row or col in cols or row in rows or \
               [col, row] in checkspots or [row, col] in spots:
                continue
            if prev + 2 + counter <= number - 1:
                if prev + 2 + counter != row:
                    continue
            if counter > (number-2)/2:
                if [row, col] not in checkspots:
                    continue
            rows.append(row)
            cols.append(col)
            spots.append([col, row])
            checkspots.append([col, row])
            prev = row
    print(spots)
    allspots.append(spots)
    counter += 1
