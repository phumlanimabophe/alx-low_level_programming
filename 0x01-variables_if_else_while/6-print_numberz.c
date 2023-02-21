/*
 * File: 6-print_numberz.c
 * 
 */

#include <stdio.h>

/**
 * main - Write a program that prints all....
 *
 * Return: Always 0.
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
		putchar((num % 10) + '0');

	putchar('\n');

	return (0);
}

