#include "main.h"

/**
 * _char - char print function
 * @args: argument list
 * @count: count parameter
*/

void _char(va_list args, int *count)
{
	char character;

	character = va_arg(args, int);
	_putchar(character);
	(*count)++;
}
