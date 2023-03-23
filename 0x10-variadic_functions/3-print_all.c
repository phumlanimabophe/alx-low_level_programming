#include "variadic_functions.h"
#include<stdio.h>
#include<stdarg.h>
/**
 * p_char - print char
 * @list:arg
 * Return: void
 */

void p_char(va_list list)
{
	printf("%c", va_arg(list, int));
}


void p_string(va_list list)
{
	char *str;

	str = va_arg(list, char*);
	if (str == NULL)
		str = "(nil)";
printf("%s", str);
}

void p_float(va_list list)
{
	printf("%f", va_arg(list, double));
}

void p_integer(va_list list)
{
	printf("%i", va_arg(list, int));
}



void print_all(const char * const format, ...)

{
	unsigned int i, j;
	t_print t[] = {
		{"c", p_char},
		{"s", p_string},
		{"i", p_integer},
		{"f", p_float},
		{NULL, NULL}
	};
	va_list valist;
	char *s = "";

	va_start(valist, format);
	i = 0;
	while (format && format[i])
	{
		j = 0;
		while (t[j].x != NULL)
		{
			if (*(t[j].x) == format[i])
			{
				printf("%s", s);
				t[j].T_func(valist);
				s = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	va_end(valist);
	printf("\n");
}
