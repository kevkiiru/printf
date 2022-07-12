#include <unistd.h>

/**
 * _putchar - writes the character to stdout
 * @c: char to print
 * Return: always 0
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
