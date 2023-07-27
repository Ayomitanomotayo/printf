#include "main.h"

/**
 * _checkprecision - handles the precision for specifiers
 * @format: First argument passed int string
 * @x: argument to be printed
 * @args: input number of arguments.
 *
 * Return: Precision.
 */
int _checkprecision(const char *format, int *x, va_list args)
{
	int current_x = *x + 1;
	int precision = -1;

	if (format[current_x] != '.')
		return (precision);
	precision = 0;
	for (current_x += 1; format[current_x] != '\0'; current_x++)
	{
		if (is_digit(format[current_x]))
		{
			precision *= 10;
			precision += format[current_x] - '0';
		}
		else if (format[current_x] == '*')
		{
			current_x++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*x = current_x - 1;
	return (precision);
}
