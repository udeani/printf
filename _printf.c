/*
 * File: _printf.c
 * Auth: Udeani henry
 */

#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void string_s(va_list arg);
void char_c(va_list arg);

/**
 * _printf - function to print any buffer to standard output
 * @format: pointer to array of characters to print
 * ...: variadic functions to handle options for the print
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int n, i = 0;

	va_list arg;

	handls functions[] =
	{
		{"s", string_s},
		{"c", char_c},
		{NULL, NULL},
	};

	va_start(arg, format);

	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			write(1, &format[n], 1);
		}
		else
		{
			n++;

			for (i = 0; *(functions[i].p); i++)
			{

				if (format[n] == *(functions[i].p))
				{
					(functions[i].va_items(arg));
				}
			}

		}
	va_end(arg);
	}
	return(0);
}

/*
 * string_s - function to prints an array of characters.
 * @arg: variadic list to print
 */
void string_s(va_list arg)
{
	long unsigned int j = 0;
	char *v = va_arg(arg, char *);

	for (j = 0; j < sizeof(v) ; j++)
		(write(1, &v[j], 1));
}

/*
 * char_c - function to print single characters
 * @arg: variadic list to print.
 */
void char_c(va_list arg)
{
	long unsigned int j = 0;
	char *v = va_arg(arg, char *);

	for (j = 0; j < sizeof(v) ; j++)
		(write(1, &v[j], 1));
}
