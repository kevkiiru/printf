#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * if_error - to return if error
 * @format: the format
 *
 */

void if_error(const char *format)
{
	if (!format || !format)
	{
		write(1, "error", 6);
		exit(98);
	}
}

/**
 * _printf - function to print anything
 * @format: the format of the string
 * Return: the printed output
 */

int _printf(const char *format, ...)
{
	int a, b, convr, flag;
	char *buffer, *conv, *format_str;
	va_list list_a;

	if_error(format);
	buffer = malloc(BUF_LENG * sizeof(char));
	_flush(buffer);
	va_start(list_a, format), flag = b = 0;

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] != '\0')
		{
			fill_buffer(buffer, format + a, b, 1);
			a += 1;
			b += 1;
		}

		if (format[a] == "%")
		{
			flag = 1, conv = grab_format(format + a);
			if (format[a + 1] == '%' || conv == NULL)
			{
				flag = (flag == 0) ? 1 : 0;
				fill_buffer(buffer, format + a, b, 1);
				a += 2;
				b += 1;
			}
		}

		if (flag == 1)
		{
			flag = 0;
			conv = grab_format(format + a);
			convr = _strlen(conv);
			format_str = get_mstring_func(conv[convr - 1])(conv, list_a);
			free(conv);
			fill_buffer(buffer, format_str, b, _strlen(format_str));
			b = b + _strlen(format_str);
			free(format_str), a += convr;
		}
	}

	print_buffer(buffer, b);
	free(buffer);
	return (b);
}
