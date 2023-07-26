#include "main.h"
/**
 * _printf - prints an input to the standard output
 * @format: contains all character
 * Return: -1 and print_char
 */
int _printf(const char *format, ...)
{
	int print_char;

	conv_t my_list[] = {
		{"c", print_char}, {"s", print_string}, {"%", print_percent},
		{"d", print_integer}, {"i", print_integer}, {"b", print_binary},
		{"r", print_reversed}, {"R", rot13}, {"u", unsigned_integer},
		{"o", print_octal}, {"x", print_hex}, {"X", print_heX}, {NULL, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	print_char = parser(format, my_list, args);
	va_end(args);

	return (print_char);
}
