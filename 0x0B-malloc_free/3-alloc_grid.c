/*
 * File: 0-reset_to_98.c
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - Allocate a 2D grid of integers
 * @width: the number of columns
 * @height: the number of rows
 *
 * Return: a pointer to the newly-allocated grid, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int row, col;

	if (width <= 0 || height <= 0)
		return NULL;

	/* Allocate memory for the grid */
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
		return NULL;

	/* Allocate memory for each row */
	for (row = 0; row < height; row++) {
		grid[row] = malloc(width * sizeof(int));
		if (grid[row] == NULL) {
			/* Free previously-allocated rows */
			for (col = 0; col < row; col++)
				free(grid[col]);
			free(grid);
			return NULL;
		}
	}

	/* Initialize each element to zero */
	for (row = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			grid[row][col] = 0;
		}
	}

	return grid;
}
