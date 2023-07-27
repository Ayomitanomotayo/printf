#include "main.h"
/**
 * _printrev - prints string in reverse
 * @precision: prec specifier
 * @diff: arg list
 * @size: size specifier
 * @width: width
 * @buffer: char buffer array
 * @flags: checks flags
 * Return: char
 */
int _printrev(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	char *s;
	char q;
	int x, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	s = va_arg(diff, char *);

	if (s == NULL)
	{
		s = ")Null(";
	}

	for (x = 0; s[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		q = s[x];

		write(1, &q, 1);
		count++;
	}
	return (count);
}

/**
 * _printrot13 - prints strings in rot13
 * @flags: checks active flags
 * @width: width
 * @precision: prec specifier
 * @buffer: array buffer
 * @size: size specifier
 * @diff: arg list
 * Return: char
 */
int _printrot13(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	char a;
	char *s;
	size_t x, y;
	int count = 0;
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	s = va_arg(diff, char *);

	UNUSED(width);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";

	for (x = 0; s[x]; x++)
	{
		for (y = 0; in[y]; y++)
		{
			if (in[y] == s[x])
			{
				a = out[y];
				write(1, &a, 1);
				count++;
				break;
			}
		}
		if (!in[y])
		{
			a = s[x];
			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}
