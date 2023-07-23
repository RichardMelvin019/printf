#include "main.h"

/**
 * _printf - printf
 * @format: format string
 * Return: formatted string
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count;
	fmt_spec symbol_matrix[] = {
		{'c', _char}, {'s', _string},
		{'\0', NULL}
	};

	va_start(args, format);
	count = 0;
	if (format != NULL)
	{
		_format(format, &count, symbol_matrix, args);
	}
	else
		return (-1);

	va_end(args);
	return (count);
}

/**
 * _format - format string
 * @format: format string
 * @count: counter
 * @symbol_matrix: symbol matrix
 * @args: arguments
 * Return: 0
*/

int _format(const char *format, int *count,
	fmt_spec symbol_matrix[], va_list args)
{
	int i;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			(*count)++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				break;
			if (format_check(format[i], symbol_matrix, args, count) == -1)
			{
				_putchar('%');
				_putchar(format[i]);
				(*count) += 2;
			}
		}
	}
	return (0);
}

/**
 * format_check - format check
 * @symbol: symbol
 * @symbol_matrix: symbol matrix
 * @args: arguments
 * @count: counter
 * Return: -1 if error, 0 if no error
*/

int format_check(char symbol, fmt_spec symbol_matrix[],
	va_list args, int *count)
{
	int row;

	if (symbol == '%')
	{
		_putchar(symbol);
		(*count)++;
		return (0);
	}

	for (row = 0; symbol_matrix[row].symbol != '\0'; row++)
	{
		if (symbol == symbol_matrix[row].symbol)
		{
			symbol_matrix[row].func_ptr(args, count);
			return (0);
		}
	}
	return (-1);
}
