#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to unsigned int
 * @index: index of the bit to clear
 *
 * Return: 1 if success, -1 otherwise
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	/* check if index is within the range of n */
	if (index >= sizeof(*n) * 8) {
		return (-1);
	}
	
	/* use bitwise AND to clear the bit at the given index */
	*n &= ~(1UL << index);

	return (1);
}
