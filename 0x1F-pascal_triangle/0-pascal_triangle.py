#!/usr/bin/python3
"""Pascal's Triangle"""


def pascal_triangle(n):
    """pascal_triangle"""
    tri = []
    if n <= 0:
        return tri
    for i in range(n):
        temp = []
        for j in range(i + 1):
            if j == 0 or j == i:
                temp.append(1)
            else:
                temp.append(tri[i - 1][j - 1] + tri[i - 1][j])
        tri.append(temp)
    return tri
