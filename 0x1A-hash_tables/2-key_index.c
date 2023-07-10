#include "hash_tables.h"

/**
 * key_index - Gives the index of a key in the hash table array.
 * @key: The key, a string.
 * @size: The size of the array of the hash table.
 *
 * Return: The index number for the key/value pair in the hash table array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    return (hash_djb2(key) % size);
}
