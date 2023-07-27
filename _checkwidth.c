#include "main.h"
/**
 * _checkwidth - Handling the width for the specifiers
 * @format: first string passed into the arguments.
 * @x: arguments to be printed.
 * @args: arguments passed.
 *
 * Return: the width.
 */
int _checkwidth(const char *format, int *i, va_list args)
{
	int current_x;
	int width = 0;

	for (current_x = *x + 1; format[current_x] != '\0'; current_x++)
	{
		if (is_digit(format[current_x]))
		{
			width *= 10;
			width += format[current_x] - '0';
		}
		else if (format[current_x] == '*')
		{
			current_x++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*x = current_x - 1;
	return (width);
}
