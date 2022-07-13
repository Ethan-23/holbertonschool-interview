#!/usr/bin/python3
"""0x1C. Island Perimeter"""


def island_perimeter(grid):
    """counts perimeter of islands in n by n grid"""
    perim = 0
    for col in range(len(grid)):
        for row in range(len(grid[col])):
            if grid[col][row] == 1:
                if grid[col + 1][row] == 0:
                    perim += 1
                if grid[col - 1][row] == 0:
                    perim += 1
                if grid[col][row + 1] == 0:
                    perim += 1
                if grid[col][row - 1] == 0:
                    perim += 1
    return(perim)
