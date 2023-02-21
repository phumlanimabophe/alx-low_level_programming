/*
 * File: 6-abs.c
 */

#include "main.h"

/**
 * _abs - Computes the absolute value of an integer.
 * @n: The integer to be computed.
 *
 * Return: The an integer.
 */

int _abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}
