#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * identifier - to return special characters
 * @len: next character
 * @arg: the argument
 *
 * Return: no of characters printed
 * Output to stdout
 */

int identifier(char len, va_list arg)
{
	int func_find;

	func_struct func[] = {
		{"c", print_char},
		{"s", print_string},
		{"%%", print_%},
		{"d", print_integer},
		{"i", print_integer_base10},
		{NULL, NULL}
	};

	for (func_find = 0; func[func_find].identifier != NULL; func_find++)
	{
		if (func[func_find].identifier[0] == len)
			return (func[func_find].print(arg));
	}
	return (0);
}

/**
 * _printf - main function
 * @format: format of the string
 *
 * Return: no of characters printed if true and -1 otherwise
 */

int _printf(const char *format, ...)
{
	unsigned int a;
	int print_ident = 0, char_print = 0;
	va_list arg;

	va_start(arg, format);

	if (format == NULL)
		return (-1);

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] != "%")
		{
			_putchar(format[a]);
			char_print++;
			continue;
		}

		if (format[a + 1] == "%")
		{
			_putchar("%");
			char_print++;
			a++;
			continue;
		}

		if (format[a + 1] == '\0')
			return (-1);

		print_ident = identifier(format[a + 1], arg);

		if (print_ident == -1 || print_ident != 0)
			a++;
		if (print_ident > 0)
			char_print += print_ident;
		if (print_ident == 0)
		{
			_putchar("%");
			char_print++;
		}
	}

	va_end(arg);
	return (char_print);
}
