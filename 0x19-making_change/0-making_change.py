#!/usr/bin/python3
"""Change comes from within"""


def makeChange(coins, total):
    """makeChange"""
    tcoins = 0
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    for i in coins:
        while total >= i:
            total -= i
            tcoins += 1
    if total > 0:
        return -1
    return tcoins
