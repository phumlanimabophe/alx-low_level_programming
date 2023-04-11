#include "main.h"

/**
 * get_endianness - check endianness
 * 
 * Return: 1 / 0
 */
int get_endianness(void)
{
    unsigned int i = 1;
    return (*(char *)&i);
}
