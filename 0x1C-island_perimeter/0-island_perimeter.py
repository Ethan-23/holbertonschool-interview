#!/usr/bin/python3
"""0x1C. Island Perimeter"""


def island_perimeter(grid):
    """counts perimeter of islands in n by n grid"""
    perim = 0
    for col in range(len(grid)):
        for row in range(len(grid[col])):
            if grid[col][row] == 1:
                if col < len(grid) - 1 and grid[col + 1][row] == 0:
                    perim += 1
                elif col == len(grid) - 1:
                    perim += 1
                if col > 0 and grid[col - 1][row] == 0:
                    perim += 1
                elif col == 0:
                    perim += 1
                if row < len(grid[col]) - 1 and grid[col][row + 1] == 0:
                    perim += 1
                elif row == len(grid[col]) - 1:
                    perim += 1
                if row > 0 and grid[col][row - 1] == 0:
                    perim += 1
                elif row == 0:
                    perim += 1
    return(perim)
