#include "main.h"
/**
 * _printpointer - prints a pointer value
 * @flags: checks active flags
 * @width: width
 * @precision: prec specifier
 * @size: size specifier
 * @diff: arg list
 * @buffer: buffer array
 * Return: char
 */
int _printpointer(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_ch = 0, padd = ' ';
	int index = BUFFER_SIZE - 2, len = 2, start_padd = 1;
	unsigned long num_add;
	char rd_to[] = "0123456789abcdef";
	void *ptr = va_arg(diff, void *);

	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	if (ptr == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';

	num_add = (unsigned long)ptr;

	while (num_add > 0)
	{
		buffer[index--] = rd_to[num_add % 16];
		num_add /= 16;
		len++;
	}

	if ((flags & F_NOT) && !(flags & F_SUB))
		padd = '0';
	if (flags & F_ADD)
		extra_ch = '+', len++;
	else if (flags & F_BLANK)
		extra_ch = ' ', len++;

	index++;
	return (_writepointer(buffer, index, len,
				width, flags, padd, extra_ch, start_padd));
}

/**
 * _printnonprintable - prints non printable chars in ascii
 * @diff: arg list
 * @flags: checks active flags
 * @width: width
 * @buffer: array buffer
 * @precision: prec specifier
 * @size: size specifier
 * Return: char
 */
int _printnonprintable(va_list diff, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = 0, mem_offset = 0;
	char *s = va_arg(diff, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[x] != '\0')
	{
		if (is_printable(s[x]))
			buffer[x + mem_offset] = s[x];
		else
			mem_offset = mem_offset + append_hexa_code(s[x], buffer, x + mem_offset);

		x++;
	}

	buffer[x + mem_offset] = '\0';

	return (write(1, buffer, x + mem_offset));
}
