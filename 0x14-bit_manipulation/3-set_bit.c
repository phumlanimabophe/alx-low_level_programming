#include "main.h"

/**
 * set_bit - set value to 1 with given index
 * @n:pointer to unsigned int
 * @index: unsigned int index
 * Return: 1 if succes -1 in case of error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(*n) * 8) return -1;
    *n |= (1UL << index);
    return 1;
}
