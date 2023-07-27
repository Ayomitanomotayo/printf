Printf project

A program for converting formatted output in C, developed as part of the low-level programming (ALX Software Engineering Programme). The program emulates the C standard library function, printf.

As required by the task we used Authorized functions and macros write (man 2 write) malloc (man 3 malloc) free (man 3 free) va_start (man 3 va_start) va_end (man 3 va_end) va_copy (man 3 va_copy) va_arg (man 3 va_arg)

We handled the following conversion specifiers TASK 0: c, s & %

TASK 1; d & i

TASK 2; b: the unsigned int argument is converted to binary

TASK 3 u, o, x & X

TASK 4: To reduce wite function calling we handled Using a local buffer of 1024 chars in order to call write as little as possible.

TASK 5: We handled the following custom conversion specifier: S : prints the string. Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

TASK 6: we handled the conversion specifier: p.

TASK 7: We Handle the following flag characters for non-custom conversion specifiers: +, space and #.

TASK 8; length modifiers for non-custom conversion specifiers: l and h on Conversion specifiers: d, i, u, o, x, X.

TASK 9; Handle the field width for non-custom conversion specifiers.

TASK 10; Handle the precision for non-custom conversion specifiers.

TASK 11; Handle the 0 flag character for non-custom conversion specifiers.

TASK 12; Handle the - flag character for non-custom conversion specifiers.

TASK 13; Handle the custom conversion specifier r: that prints the reversed string

TASK 14; we Handled custom conversion specifier R:that prints the rot13'ed string
