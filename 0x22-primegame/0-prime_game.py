#!/usr/bin/python3
"""Prime Game"""


def isWinner(x, nums):
    """Prime Game"""
    winner = [0, 0]
    for roundnum in range(x):
        tempx = []
        for i in range(nums[roundnum]):
            if i != 0:
                tempx.append(i + 1)
            for turn in range(len(tempx)):
                for check in range(turn + 1, len(tempx)):
                    if tempx[check] % tempx[turn] == 0:
                        tempx.pop(check)

        if tempx == []:
            winner[0] += 1
        elif len(tempx) % 2 != 0:
            winner[1] += 1
        elif len(tempx) % 2 == 0:
            winner[0] += 1

    if winner[0] > winner[1]:
        return("Ben")
    else:
        return("Maria")
