#include "main.h"
/**
 * _printunsigned - prints an unsigned int
 * @precision: prec specifier
 * @width: width
 * @size: size specifier
 * @flags: check flags
 * @diff: arg lists
 * @buffer: array bufer
 * Return: chars printed
 */
int _printunsigned(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = BUFFER_SIZE - 2;
	unsigned long int num1 = va_arg(diff, unsigned long int);

	num1 = convert_size_unsgnd(num1, size);

	if (num1 == 0)
		buffer[x--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num1 > 0)
	{
		buffer[x--] = (num1 % 10) + '0';
		num1 /= 10;
	}
	x++;
	return (_writeunsgnd(0, x, buffer, flags, width, precision, size));
}

/**
 * _printoctal - prints an unsigned number
 * @width: width
 * @precision: prec specifier
 * @flags: checks active flags
 * @diff: args list
 * @size: size specifier
 * @buffer: array buffer
 * Return: chars printed
 */
int _printoctal(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = BUFFER_SIZE - 2;
	unsigned long int num1 = va_arg(diff, unsigned long int);
	unsigned long int num2 = num1;

	UNUSED(width);

	num1 = convert_size_unsgnd(num1, size);

	if (num1 == 0)
		buffer[x--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num1 > 0)
	{
		buffer[x--] = (num1 % 8) + '0';
		num1 /= 8;
	}

	if (flags & HASH_VAL && num2 != 0)
		buffer[x--] = '0';

	x++;
	return (_writeunsgnd(0, x, buffer, flags, width, precision, size));
}
