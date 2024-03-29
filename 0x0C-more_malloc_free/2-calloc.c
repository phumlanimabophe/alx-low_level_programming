#include "main.h"
#include <stdlib.h>
#include "main.h"
#include <stdlib.h>
#include <stdlib.h>

/**
 * _bzero - set all the bytes to 0.
 * @dst: pointer to propagate.
 * @size: of the memory per-byte.
 *
 * Return: pointer to memory area dst.
 */
void *_bzero(void *dst, unsigned int size)
{
    char *d = dst;

    do
        *d++ = 0;
    while (--size != 0);

    return dst;
}

/**
 * _calloc - create and array using calloc
 * @nmemb: number elements.
 * @size: size of the type.
 *
 * Return: pointer to the memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    void *ptr;

    if (!nmemb || !size)
        return NULL;

    ptr = malloc(nmemb * size);

    if (!ptr)
        return NULL;

    _bzero(ptr, nmemb * size);
    return ptr;
}

