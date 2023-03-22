#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments
 *
 * Description: This program prints the opcodes of its own main function in hexadecimal.
 *
 * Return: 0 on success, 1 on invalid number of arguments, and 2 on negative argument.
 */

int main(int argc, char *argv[])
{
  int i, n;

  if (argc != 2)
  {
    printf("Error\n");
    return 1;
  }

  n = atoi(argv[1]);

  if (n < 0)
  {
    printf("Error\n");
    return 2;
  }

  for (i = 0; i < n; i++)
  {
    printf("%02x", *((unsigned char *)(main + i)));
    if (i < n - 1)
      printf(" ");
    else
      printf("\n");
  }

  return 0;
}
