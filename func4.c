#include "main.h"
/**
 * _printhex - prints size_t in hexa notation
 * @diff: arg list
 * @buffer: array buffer
 * @width: width
 * @precision: prec specifier
 * @size: size specifier
 * @flags: checks active flags
 * Return: char
 */
int _printhex(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hex(diff, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * _printhexupper - prints num in upper hexa decimal
 * @diff: arg list
 * @precision: prec specifier
 * @width: width
 * @buffer: array buffer
 * @size: size specifier
 * @flags: checks active flags
 * Return: char
 */
int _printhexupper(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hex(diff, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * _printhex - prints hexa in lower case
 * @precision: prec specifier
 * @diff: arg list
 * @flag_c: checks active flags
 * @rd_to: array values
 * @flags: checks active flags
 * @buffer: array buffer
 * @width: width
 * @size: size specifier
 * Return: char
 */
int print_hex(va_list diff, char rd_to[], char buffer[],
		int flags, char flag_c, int width, int precision, int size)
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
		buffer[x--] = rd_to[num1 % 16];
		num1 /= 16;
	}

	if (flags & HASH_val && num2 != 0)
	{
		buffer[x--] = flag_c;
		buffer[x--] = '0';
	}

	return (_writeunsgnd(0, x, buffer, flags, width, precision, size));
}
