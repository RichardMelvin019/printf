#include "main.h"

/**
* _dec - decimal specifier
* @args: argument list
* @count: argument count
* Return: void
*/

void _dec(va_list args, int *count)
{
	int dec;

	dec = va_arg(args, int);
	num = dec;
	
	num_len = 0;
	while (num_cpy / 10 != 0)
	{
		num_len++;
		num_cpy = num_cpy / 10;
	}
	num_len++;

	digits = malloc(sizeof(char) * num_len + 1);
	if (digits == NULL)
		return ;
	
	j = 0;
	while (num / 10 != 0)
	{

	}

	for (i = 0; ; i++)
	{
		_putchar(digits[i]);
		(*count)++;
	}	
}
