#!/usr/bin/python3
"""Rain"""


def rain(walls):
    """Rain"""
    print(walls)
    amount = 0
    for i in range(len(walls)):
        if walls[i] != 0:
            for j in range(i, len(walls)):
                if j != i and walls[j] != 0:
                    if walls[j] < walls[i]:
                        low = walls[j]
                    else:
                        low = walls[i]
                    amount += low * (j - i - 1)
                    break
    return amount
