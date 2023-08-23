#!/usr/bin/python3
"""Defines a function to calculate the perimeter of an island."""


def island_perimeter(grid):
    """Return the perimeter of an island."""
    rows, cols = len(grid), len(grid[0])
    perimeter = 0
    neighbours = [(-1, 0), (0, -1), (1, 0), (0, 1)]

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                for ni, nj in neighbours:
                    ni, nj = i + ni, j + nj
                    if 0 <= ni < rows and 0 <= nj < cols and grid[ni][nj] == 1:
                        perimeter -= 1

    return perimeter
