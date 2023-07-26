#include "main.h"
/**
 * parser - recieves different parameter
 * @format: cointains all character
 * @args: argumentents passed to the program
 * @my_list: list of functions
 * Return: printed chars
 */
int parser(const char *format, conv_t my_list[], va_list args)
{
	int y, x, rev, print_char;

	print_char = 0;
	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			for (y = 0; my_list[y].op != NULL; y++)
			{
				if (format[x + 1] == my_list[y].op[0])
				{
					rev = my_list[y].fmt(args);
					if (rev == -1)
						return (-1);

					print_char = print_char + rev;
					break;
				}
			}
			if (my_list[y].op == NULL && format[x + 1] != ' ')
			{
				if (format[x + 1] != '\0')
				{
					write_char(format[x]);
					write_char(format[x + 1]);
					print_char += 2
				}
				else
					return (-1);
			}
			x = x + 1;
		}
		else
		{
			write_char(format[x]);
			print_char++;
		}
	}
	return (print_char);
}
