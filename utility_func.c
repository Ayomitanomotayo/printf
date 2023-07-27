#include "main.h"
/**
 * is_printable - check if char is printable
 * @a: char to check
 * Return: 0
 */
int is_printable(char a)
{
	if (a >= 32 && a < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Add ASCII char in hexadecimal rep to a buffer
 * @ascii_val: ascii code
 * @buffer: array buffer
 * @x: start int to append
 * Return: 3
 */
int append_hexa_code(char ascii_val, char buffer[], int x)
{
	char rd_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_val = ascii_val * -1;

	buffer[x++] = '\\';
	buffer[x++] = 'x';

	buffer[x++] = rd_to[ascii_val / 16];
	buffer[x] = rd_to[ascii_val % 16];

	return (3);
}
