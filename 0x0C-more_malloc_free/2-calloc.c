#include "main.h"
#include <stdlib.h>
/*
 * Allocates memory for an array of nmemb elements, each of size bytes.
 * The memory is initialized to zero.
 * If nmemb or size is zero, returns NULL.
 * Returns a pointer to the allocated memory, or NULL on error.
 */
void *allocate_zeroed_memory(unsigned int nmemb, unsigned int size)
{
    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    unsigned int total_size = nmemb * size;
    char *mem = malloc(total_size);
    if (mem == NULL) {
        return NULL;
    }

    memset(mem, 0, total_size);
    return mem;
}
