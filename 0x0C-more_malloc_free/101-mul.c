#include <stdlib.h>
#include <stdio.h>

/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: input integer.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string.
 * @s: input string.
 *
 * Return: length of the input string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * mul - multiplies two numbers.
 * @num1: first input number.
 * @num2: second input number.
 *
 * Return: pointer to the result string.
 */
char *mul(char *num1, char *num2)
{
	int len1, len2, i, j, n1, n2, carry = 0, sum = 0;
	char *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		j = len2 - 1;
		while (j >= 0)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + (result[i + j + 1] - '0') + carry;
			carry = sum / 10;
			result[i + j + 1] = (sum % 10) + '0';
			j--;
		}
		if (carry > 0)
			result[i + j + 1] += carry;
	}
	while (*result == '0' && *(result + 1))
		result++;

	return (result);
}

/**
 * main - multiplies two positive numbers.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	char *result;
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (!_isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (98);
			}
		}
	}
	result = mul(argv[1], argv[2]);
	printf("%s\n", result);
	free(result);
	return (0);
}
