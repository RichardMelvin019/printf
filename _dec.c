#include "main.h"

/**
* _dec - decimal specifier
* @args: argument list
* @count: argument count
* Return: void
*/

void _dec(va_list args, int *count)
{
	int dec, i, j, num_len;
	unsigned int num, pos_num;
	char *digits;

	dec = va_arg(args, int);
	if (dec < 0)
		pos_num  = dec * -1;
	else
		pos_num = dec;
	num = pos_num;
	num_len = 0;
	while (pos_num / 10 != 0)
	{
		num_len++;
		pos_num = pos_num / 10;
	}
	num_len++;
	digits = malloc(sizeof(char) * num_len + 1);
	if (digits == NULL)
		return;

	j = 0;
	while (num / 10 != 0)
	{
		digits[j] = (num % 10) + '0';
		num = num / 10;
		j++;
	}
	digits[j] = (num % 10) + '0';
	if (dec < 0)
	{
		_putchar('-');
		(*count)++;
	}
	for (i = j; i >= 0; i--)
	{
		_putchar(digits[i]);
		(*count)++;
	}
	free(digits);
}
