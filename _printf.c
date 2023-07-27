#include "main.h"
/**
 * _printbuf - Print existing buffer
 * @buffer: Array of chars
 * @buffer_index: buffer Index to add char stored in buffer
 */
void _printbuff(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	write(1, &buffer[0], *buffer_index);
	*buffer_index = 0;
}
/**
 * _printf - function to printf implementation
 * @format: format which is the first arguments
 * Return: chars printed to the stdout
 */
int _printf(const char *format, ...)
{
	int x, print = 0, print_char = 0;
	int size, width, precision, flags, buffer_index = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
	return (-1);
	va_start(args, format);
	for (x = 0; format && format[x] != '\0'; x++)
	{
	if (format[x] != '%')
	{
		buffer[buffer_index++] = format[x];
		if (buffer_index == BUFFER_SIZE)
			_printbuffer(buffer, &buffer_index);
			print_char++;
	}
		else
	{
			_printbuffer(buffer, &buffer_index);
			flags = _checkflags(format, &x);
			width = _checkwidth(format, &x, args);
			precision = _checkprecision(format, &x, args);
			size = _checksize(format, &x);
			++x;
			printed = handle_print(format, &x, args, buffer,
				size, width, precision, flag);
			if (print == -1)
				return (-1);
		print_char += print;
	}
	}
	_printbuffer(buffer, &buffer_index);
	va_end(args);
	return (print_char);
}
