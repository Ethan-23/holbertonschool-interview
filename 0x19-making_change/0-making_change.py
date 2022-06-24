#!/usr/bin/python3
"""
Uses given list of coins to calculate how many you need to reach the total
"""


def makeChange(coins, total):

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
