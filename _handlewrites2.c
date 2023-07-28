#include "main.h"
/**
 * _writeunsgnd - Writes an unsigned numbers to stdout
 * @is_neg: To test for negative number
 * @index: Indexing numbber in the buffer
 * @buffer: buffer contining Array of chars
 * @flags: check for Flags specifiers
 * @width: to check for Width specifier
 * @precision: check for Precision
 * @size: check for Size specifier
 *
 * Return: written chars.
 */
int _writeunsgnd(int is_neg, int index,
	char buffer[], int size, int width, int precision, int flags)
{
	int len = BUFFER_SIZE - index - 1, x = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(size);
	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}
	if ((flags & F_NOT) && !(flags & F_SUB))
		padd = '0';
	if (width > len)
	{
		for (x = 0; x < width - len; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & F_SUB)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], x));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[index], len));
		}
	}
	return (write(1, &buffer[index], len));
}
/**
 * _writepointer - print the  memory address stored to stdout
 * @buffer: Arrays of chars
 * @index: Indexing the buffer
 * @len: number leght
 * @width: check for width specifier
 * @flags: checks Flags
 * @padd: Char representing the padding
 * @extra_ch: Char that saves extra char
 * @start_padd: Index at which padding should start
 *
 * Return: written chars.
 */
int _writepointer(char buffer[], int index, int flags, int width, int len,
	char padd, char extra_ch, int start_padd)
{
	int x;

	if (width > len)
	{
		for (x = 3; x < width - len + 3; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & F_SUB && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], x - 3));
		}
		else if (!(flags & F_SUB) && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[3], x - 3) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_SUB) && padd == '0')
		{
			if (extra_ch)
				buffer[--start_padd] = extra_ch;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[start_padd], x - start_padd) +
				write(1, &buffer[index], len - (1 - start_padd) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_ch)
		buffer[--index] = extra_ch;
	return (write(1, &buffer[index], BUFFER_SIZE - index - 1));
}
