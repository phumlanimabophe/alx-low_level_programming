#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int length = 10;
    char *password = malloc(length + 1);

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int index = rand() % (sizeof(charset) - 1);
        password[i] = charset[index];
    }

    password[length] = '\0';

    printf("%s\n", password);

    free(password);

    return 0;
}
