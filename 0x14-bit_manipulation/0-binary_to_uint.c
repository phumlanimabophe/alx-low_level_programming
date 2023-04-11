#include "main.h"



/**
 * binary_to_uint - convert binary to unsigned int
 * @b:string from 0 and 1 else NULL
 * Return:unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
    if (!b) return 0;
    unsigned int res = 0;
    while (*b)
    {
        if (*b != '0' && *b != '1') return 0;
        res = (res << 1) + (*b++ - '0');
    }
    return res;
}
