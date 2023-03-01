#include <stdio.h>
#include <string.h>

char* infinite_add(char* n1, char* n2, char* r, int size_r) {
    // Initialize variables
    int len1 = strlen(n1), len2 = strlen(n2);
    int len_max = len1 > len2 ? len1 : len2;
    int carry = 0, sum = 0;

    // Check if result can be stored in r
    if (len_max + 1 > size_r) {
        return 0;
    }

    // Add digits from right to left
    int i = 0;
    for (i = 0; i < len_max; i++) {
        int dig1 = i < len1 ? n1[len1 - 1 - i] - '0' : 0;
        int dig2 = i < len2 ? n2[len2 - 1 - i] - '0' : 0;
        sum = dig1 + dig2 + carry;
        carry = sum / 10;
        r[len_max - i - 1] = (sum % 10) + '0';
    }

    // Add carry to the next digit
    if (carry > 0) {
        if (i + 1 > size_r) {
            return 0;
        }
        r[len_max - i - 1] = carry + '0';
        i++;
    }

    // Add null terminator and reverse the result
    r[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char tmp = r[j];
        r[j] = r[i - 1 - j];
        r[i - 1 - j] = tmp;
    }

    // Return the result pointer
    return r;
}
