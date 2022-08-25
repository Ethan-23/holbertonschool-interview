#!/usr/bin/python3
"""Prime Game"""


def isWinner(x, nums):
    """Prime Game"""
    winner = [0, 0]

    
    for roundnum in range(x):
        prime = []
        tempx = []
        for i in range(nums[roundnum]):
            if i != 0:
                tempx.append(i + 1)
        for i in tempx:
            c = 0
            for j in range(1, i):
                if i % j == 0:
                    c += 1
            if c == 1:
                prime.append(i)

        if prime == []:
            winner[0] += 1
        elif len(prime) % 2 != 0:
            winner[1] += 1
        elif len(prime) % 2 == 0:
            winner[0] += 1

    if winner[0] > winner[1]:
        return("Ben")
    else:
        return("Maria")
