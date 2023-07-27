#include "main.h"

/**
 * _checkflags - assigns flags to pecifiers
 * @format: string in which to print the arguments
 * @x: takes arguments
 * Return: Flags
 */
int _checkflags(const char *format, int *x)
{
	int y, current_x;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_SUB, F_ADD, F_NOT, HASH_VAL, F_BLANK, 0};

	for (current_x = *x + 1; format[current_x] != '\0'; current_x++)
	{
		for (y = 0; FLAGS_CH[y] != '\0'; y++)
			if (format[current_x] == FLAGS_CH[y])
			{
				flags |= FLAGS_ARR[y];
				break;
			}
		if (FLAGS_CH[y] == 0)
			break;
	}

	*x = current_x - 1;
	return (flags);
}
