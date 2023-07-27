#include "main.h"
/**
 * _checkspecifier - Prints specifiers based type
 * @f: print formated string fromarguments
 * @args: arguments to be printed.
 * @index: indexing the buffer
 * @buffer: Buffer array to handle print.
 * @flags: handling flags
 * @width: handling width.
 * @precision: handling Precision specification
 * @size: handling sizei
 * Return: 1 or 2;
 */
int _checkspecifier(const char *f, int *index, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int x, u_lenght = 0, print_char = -1;
	fmt_t fmt_types[] = {
		{'c', _printchar}, {'s', _printstring}, {'%', _printcent},
		{'i', _printint}, {'d', _printint}, {'b', _print_bin},
		{'u', _printunsigned}, {'o', _printoct}, {'x', _printhex},
		{'X', _printhexupper}, {'p', _printpointer}, {'S', _printnonprintable},
		{'r', _printrev}, {'R', _printrot13}, {'\0', NULL}
	};
	for (x = 0; fmt_types[x].f != '\0'; x++)
		if (f[*index] == fmt_types[x].f)
			return (fmt_types[x].fn(args, buffer, flags, width, precision, size));

	if (fmt_types[x].f == '\0')
	{
		if (f[*index] == '\0')
			return (-1);
		u_lenght += write(1, "%%", 1);
		if (f[*index - 1] == ' ')
			u_lenght += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while ([*index] != ' ' && f[*index] != '%')
				--(*index);
			if (f[*index] == ' ')
				--(*index);
			return (1);
		}
		u_lenght += write(1, &f[*index], 1);
		return (u_lenght);
	}
	return (print_char);
}
