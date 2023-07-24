#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct format_spec - Format Specifiers
 * @symbol: symbol to format
 * @func_ptr: function pointer
 */

typedef struct format_spec
{
	char symbol;
	void (*func_ptr)(va_list args, int *count);
} fmt_spec;

int _printf(const char *format, ...);
int _putchar(char c);
int _format(const char *format, int *count,
fmt_spec symbol_matrix[], va_list args);
int format_check(char symbol, fmt_spec symbol_matrix[],
va_list args, int *count);
void _char(va_list args, int *count);
void _string(va_list args, int *count);

#endif /* MAIN_H */
