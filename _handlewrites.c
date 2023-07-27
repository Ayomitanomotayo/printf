#include "main.h"
/**
 * _writenumber - writes string
 * @is_neg: Listing arguments to take
 * @index: character data types indexing.
 * @buffer: array of buffer for handling printf fun
 * @flags:  handling flags
 * @width: check for width.
 * @precision: check for precision
 * @size: check for of Size specifier
 *
 * Return: printed chars type.
 */
int _writenumber(int is_neg, int index, char buffer[], int size,
	int width, int precision, int flags)
{
	int len = BUFFER_SIZE - index - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);
	if ((flags & F_NOT) && !(flags & F_SUB))
		padd = '0';
	if (is_neg)
		extra_ch = '-';
	else if (flags & F_ADD)
		extra_ch = '+';
	else if (flags & F_BLANK)
		extra_ch = ' ';
	return (_writenum(index, buffer, flags, width, precision,
		len, padd, extra_ch));
}
/**
 * _writechar - write a string to stdout
 * @ch: char data types.
 * @buffer: Buffer array to store char
 * @flags:  handle flags.
 * @width: handle width.
 * @precision: check precision
 * @size: check for Size specifier
 *
 * Return: printed char
 */
int _writechar(char ch, char buffer[],
	int size, int width, int precision, int flags)
{
	int x = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags & F_NOT)
		padd = '0';
	buffer[x++] = ch;
	buffer[x] = '\0';
	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer[BUFFER_SIZE - x - 2] = padd;
		if (flags & F_SUB)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - x - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - x - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**
 * _writenum - Write number from bufffer array
 * @index: Index to start writing from array
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @length: Number length
 * @padd: char Padding
 * @extra_ch: Add an extra char
 *
 * Return: Char printed.
 */
int _writenum(int index, char buffer[],
	int padd, int width, int precision,
	int len, char flags, char extra_ch)
{
	int x, start_padd = 1;

	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
		buffer[--index] = '0', len++;
	if (extra_ch != 0)
		len++;
	if (width > len)
	{
		for (x = 1; x < width - len + 1; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & F_SUB && padd == ' ')
		{
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & F_SUB) && padd == ' ')
		{
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_SUB) && padd == '0')
		{
			if (extra_ch)
				buffer[--start_padd] = extra_ch;
			return (write(1, &buffer[start_padd], x - start_padd) +
				write(1, &buffer[index], len - (1 - start_padd)));
		}
	}
	if (extra_ch)
		buffer[--index] = extra_ch;
	return (write(1, &buffer[index], len));
}
