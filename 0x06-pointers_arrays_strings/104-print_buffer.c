#include <stdio.h>
#include <ctype.h>

void print_buffer(char *b, int size) {
    if (size <= 0) {
        printf("\n");
        return;
    }

    int i, j;
    for (i = 0; i < size; i += 10) {
        printf("%08x ", i);
        for (j = i; j < i + 10 && j < size; j += 2) {
            printf("%02x%02x ", b[j], j + 1 < size ? b[j+1] : 0);
        }
        for (; j < i + 10; j += 2) {
            printf("     ");
        }
        printf(" ");
        for (j = i; j < i + 10 && j < size; j++) {
            printf("%c", isprint(b[j]) ? b[j] : '.');
        }
        printf("\n");
    }
}
