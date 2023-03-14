/*
 * File: 0-reset_to_98.c
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - Frees a 2D array of integers
 * @grid: The array to be freed
 * @height: The number of rows in the array
 */
void free_grid(int **grid, int height)
{
    int i;
    int *p;

    for (i = 0; i < height; i++) {
        p = grid[i];
        free(p);
    }
    free(grid);
}
