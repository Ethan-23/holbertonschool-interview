#!/usr/bin/python3
"""0. Rain"""


def rain(walls):
    """
    Checks the amount of space between walls
    (amount of spaces between numbers in array width & height)
    """
    amount = 0
    
    for i in range(len(walls)):
        sub = 0
        if walls[i] != 0:
            for j in range(i, len(walls)):
                if j != i and walls[j] != 0:
                    if walls[j] < walls[i]:
                        low = walls[j]
                    else:
                        low = walls[i]
                    check = low * (j - i - 1)
                    if check == 0:
                        sub += walls[j]
                        continue    
                    amount += check - sub
                    break
    return amount
