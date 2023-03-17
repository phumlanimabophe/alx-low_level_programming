#include "main.h"
#include <stdlib.h>
/*
 * Creates an array of integers from min to max (inclusive).
 * If min is greater than max, returns NULL.
 * Returns a pointer to the allocated array, or NULL on error.
 */
int *create_integer_array(int min, int max)
{
    if (min > max) {
        return NULL;
    }

    int array_size = max - min + 1;
    int *int_array = malloc(array_size * sizeof(int));
    if (int_array == NULL) {
        return NULL;
    }

    for (int i = 0; i < array_size; i++) {
        int_array[i] = min + i;
    }

    return int_array;
}
