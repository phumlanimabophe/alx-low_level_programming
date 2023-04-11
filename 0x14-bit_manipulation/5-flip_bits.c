#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 * @m : unsigned long int
 * @n : unsigned long int
 * @m : unsigned long int
 * Return: number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int t = n ^ m;
    unsigned int count = 0;
    while (t)
    {
        count += t & 1;
        t >>= 1;
    }
    return count;
}
