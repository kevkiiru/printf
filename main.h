#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>


int _printf(const char *format, ...);
int _putchar(char c);


/**
 * struct identifier_struct - definition structure 
 * @identifier: type
 * @print: function to print
*/

typedef struct identifier_struct
{
	char *identifier;
	int (*print)(va_list);
} identifier_struct;







#endif
