#include "main.h"
/**
 * print_char - Prints a character
 * @buffer: Buffer array
 * @width: Width
 * @diff: List a of args
 * @flags: check for active flags
 * @precision: Precision
 * @size: Size specifier
 * Return: chars printed
 */
int _printchar(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	char ch = va_arg(diff, int);

	return (_writechar(ch, buffer, flags, width, precision, size));
}

/**
 * print_string - prints a string
 * @buffer: Buffer array
 * @width: Width
 * @diff: List a of args
 * @flags: check for active flags
 * @precision: Precision
 * @size: Size specifier
 * Return: chars
 */
int _printstring(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	int x, len = 0;
	char *s = va_arg(diff, char *);

	UNUSED(flags);
	UNUSED(precision);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(width);

	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[len] != '\0')
	len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_SUB)
		{
			write(1, &s[0], len);
			for (x = width - len; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - len; x > 0; x--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (width);
		}
	}
	return (write(1, s, len));
}
