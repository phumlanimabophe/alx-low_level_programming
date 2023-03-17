#include "main.h"
#include <stdlib.h>
/*
 * Concatenate two strings, up to n characters of the second string.
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
    unsigned int len2 = strlen(s2);

    if (len2 > n) {
        len2 = n;
    }

    char *result = malloc(len1 + len2 + 1);
    if (result == NULL) {
        return NULL;
    }

    strcpy(result, s1);
    strncat(result, s2, len2);

    return result;
}
