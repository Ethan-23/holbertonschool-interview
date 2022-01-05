#!/usr/bin/python3
"""0. Minimum Operations"""


def minOperations(n):
    """
    Finds the least amount of steps to reach n starting from 1
    Copy all / Paste
    Returns an integer
    """

    if n <= 0:
        return 0
    if type(n) != int:
        return 0
    step = 0
    increase = 0
    i = 1
    while i < n:
        if n % (increase+1) == 0 and i < n/2 or n % (increase+2) != 0:
            step += 1
            increase = i
        i += increase
        step += 1
    return step
