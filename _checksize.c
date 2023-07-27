#include "main.h"

/**
 * _checksize - To handle the size passed into the argument
 * @format: String from the first argument
 * @x: arguments passed to the function.
 *
 * Return: Precision.
 */
int _checksize(const char *format, int *x)
{
	int current_x = *x + 1;
	int size = 0;

	if (format[current_x] == 'l')
		size = S_LONG;
	else if (format[current_x] == 'h')
		size = S_SHORT;
	if (size == 0)
		*x = current_x - 1;
	else
		*x = current_x;
	return (size);
}
