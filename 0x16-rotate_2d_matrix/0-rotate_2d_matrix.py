#!/usr/bin/python3
"""Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """Rotates given matrix 90 degrees"""
    startcol = 0
    startrow = len(matrix) - 1
    temp = []
    copy = []
    for i in range(len(matrix)):
        temp = []
        for j in range(len(matrix[0])):
            temp.append(matrix[i][j])
        copy.append(temp)
    for row in range(len(matrix)):
        if row != 0:
            startrow = len(matrix[0]) - 1
            startcol += 1
        for col in range(len(matrix[0])):
            matrix[row][col] = copy[startrow][startcol]
            startrow -= 1
