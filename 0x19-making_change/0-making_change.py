#!/usr/bin/python3
"""
Uses given list of coins to calculate how many you need to reach the total
"""


def makeChange(coins, total):
    """
    makeChange
    coins: List of given coins
    total: Total that needs to be met with coins
    """
    tcoins = 0
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    for i in coins:
        tcoins += total // i
        total = total % i
    if total > 0:
        return -1
    return tcoins
