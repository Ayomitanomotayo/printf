#include "main.h"
/**
 * is_digit - checks if char is digit
 * @a: char to check
 * Return: 1 or 0
 */
int is_digit(char a)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Converts a number to a specified size
 * @num1: num to be created
 * @size: size of type to be created
 * Return: int val
 */
long int convert_size_number(long int num1, int size)
{
	if (size == S_LONG)
		return (num1);
	else if (size == S_SHORT)
		return ((short)num1);

	return ((int)num1);
}

/**
 * convert_size_unsgnd - Converts a number to a specified size
 * @size: size of type to be created
 * @num1: num to be created
 * Return: int val
 */
long int convert_size_unsgnd(unsigned long int num1, int size)
{
	if (size == S_LONG)
		return (num1);
	else if (size == S_SHORT)
		return ((unsigned short)num1);

	return ((size_t)num1);
}
