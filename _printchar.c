#include "main.h"
/**
 * write - To print to stdout in place of printf
 *@c: character to print
 *
 * Return: Always success.
 */
int write_char(char c)
{
        return(write(1, &C, 1));
}
/**
 * print_char - Prints character
 * @list:to access variable  arguments passed into the printf func
 *
 * Return: The printed char
 */
int print_char(va_list list)
{
        write_char(va_arg(list, int));
        return (1);
}
/**
 *print_string - Prints string to stdout
 *@list: To access variable argument passed into printf
 *
 * Return: The printed strings until NULL
 */
int print_string(va_list list)
{
        int x;
        char *str;

        str = va_arg(list, char *);
        if (str == NULL)
                str = "(null)";
        for (x = 0; str[x] != '\0'; x++)
		       write_char(str[x]);
        return (x);
}
/**
 * print_cent - Prints a percent symbol
 * @list: Accesses the variable list of arguments passed to printf func
 * Return: Return the inputed characteri
 */
int print_cent(__attribute__((unused))va_list list)
{
        write_char('%');
        return (1);
}
