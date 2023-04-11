#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @index:index unsigned int
 * @n: unsigned int
 * Return: bit at given index else -1 if error accured
 */
int get_bit(unsigned long int n, unsigned int index)
{
    if (index >= sizeof(n) * 8) return -1;
    return (n >> index) & 1;
}
