#include "main.h"
/**
 * _printpercent - prints a percent sign
 * @flags: checks flags
 * @buffer: buffer array
 * @width: width
 * @precision: precison
 * @size: size specifier
 * @diff: arg list
 * Return: %
 */
int _printpercent(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(diff);
	return (write(1, "%%", 1));
}

/**
 * _printint - prints an integer
 * @buffer: Buffer array
 * @flags: checks flags
 * @size: size specifier
 * @diff: arg list
 * @precision: precison
 * @width: width
 * Return: char
 */
int _printint(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = BUFFER_SIZE - 2;
	int neg = 0;
	long int v = va_arg(diff, long int);
	unsigned long int num1;

	v = convert_size_number(v, size);

	if (v == 0)
		buffer[x--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num1 = (unsigned long int)v;

	if (v < 0)
	{
		num1 = (unsigned long int)((-1) * v);
		neg = 1;
	}

	while (num1 > 0)
	{
		buffer[x--] = (num1 % 10) + '0';
		num1 /= 10;
	}
	x++;

	return (_writenumber(neg, x, buffer, flags, width, precision, size));
}

/**
 * _printbinary - prints  a size_t num
 * @width: width
 * @precision: preci specifier
 * @size: size specifier
 * @flags: checks for flags
 * @buffer: buff array
 * @diff: arg list
 * Return: count
 */
int _printbinary(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	size_t x, v, w, total;
	size_t b[32];
	int add;
	char q;

	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);
	UNUSED(buffer);

	v = va_arg(diff, unsigned int);
	w = 2147483648;
	b[0] = v / w;

	for (x = 1; x < 32; x++)
	{
		w /= 2;
		b[x] = (v / w) % 2;
	}
	for (x = 0, total = 0, add = 0; x < 32; x++)
	{
		total = total + b[x];
		if (total || x == 31)
		{
			q = '0' + b[x];
			write(1, &q, 1);
			add++;
		}
	}
	return (add);
}
