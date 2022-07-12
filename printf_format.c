#include "main.h"

/**
<<<<<<< HEAD
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
=======
>>>>>>> db3e0c7b4889040a0cac081e5669120785c38a4c
 * _printf - main function
 * @format: the string
 *
 * Return: the characters printed
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], ibuf), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
	return (len);
}
