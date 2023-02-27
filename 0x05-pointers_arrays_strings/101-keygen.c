#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int n = 612852475143;
	unsigned long int largest_prime = 2;

	while (n > largest_prime)
	{
		if (n % largest_prime == 0)
			n /= largest_prime;
		else
			largest_prime++;
	}

	printf("%lu\n", largest_prime);

	return (0);
}
