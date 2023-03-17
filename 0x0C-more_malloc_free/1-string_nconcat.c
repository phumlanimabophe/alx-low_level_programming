#include "main.h"
#include <stdlib.h>

/*
 * Concatenates two strings, up to n characters of the second string.
 * If s1 or s2 are NULL, treat them as empty strings.
 * Returns a new string that must be freed by the caller, or NULL on error.
 */
char *concat_strings(char *s1, char *s2, unsigned int n)
{
    if (s1 == NULL) {
        s1 = "";
    }

    if (s2 == NULL) {
        s2 = "";
    }

    unsigned int len1 = strlen(s1);
    unsigned int len2 = strnlen(s2, n);

    char *result = malloc(len1 + len2 + 1);
    if (result == NULL) {
        return NULL;
    }

    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2);
    result[len1 + len2] = '\0';

    return result;
}
