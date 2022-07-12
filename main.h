#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);


/**
 * struct func_struct - definition structure 
 * @identifier: type
 * @print: function to print
*/

typedef struct func_struct
{
	char *identifier;
	int (*print)(va_list);
} identifier;







#endif
