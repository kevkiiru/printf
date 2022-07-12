#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>


int _printf(const char *format, ...);
int _putchar(char c);


/**
 * struct func_struct - definition structure 
 * @identifier: type
 * @print: function to print
*/

typedef struct func_struct
{
	char *identifier;
	int (*print)(va_list);
} func_struct;







#endif
