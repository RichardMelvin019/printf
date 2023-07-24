#include "main.h"

/**
 * _string - string print function
 * @args: argument list
 * @count: count parameter
*/

void _string(va_list args, int *count)
{
	char *string;
	int i;

	string = va_arg(args, char *);
	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i] != '\0'; i++)
	{
		_putchar(string[i]);
		(*count)++;
	}
}
