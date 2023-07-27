#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define S_LONG 2
#define S_SHORT 1

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

#define F_SUB 1
#define F_ADD 2
#define F_NOT 4
#define HASH_VAL 8
#define F_BLANK 16

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct f
{
	char f;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct f fmt_t;

int _printf(const char *format, ...);
int _checkspecifier(const char *f, int *index, va_list args, char buffer[],
	int flags, int width, int precision, int size);
int _printchar(va_list diff, char buffer[],
	int flags, int width, int precision, int size);
int _printstring(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printpercent(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printint(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printbinary(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printunsigned(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printoctal(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printhex(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printhexupper(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int print_hex(va_list diff, char rd_to[], char buffer[],
		int flags, char flag_c, int width, int precision, int size);
int _printpointer(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printnonprintable(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printrev(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _printrot13(va_list diff, char buffer[],
		int flags, int width, int precision, int size);
int _checkflags(const char *format, int *x);
int _checkprecision(const char *format, int *x, va_list args);
int _checksize(const char *format, int *x);
int _checkwidth(const char *format, int *i, va_list args);
int _writenumber(int is_neg, int index, char buffer[], int size,
	int width, int precision, int flags);
int _writechar(char ch, char buffer[],
	int size, int width, int precision, int flags);
int _writenum(int index, char buffer[],int padd, int width, int precision,
	int len, char flags, char extra_ch);
int _writeunsgnd(int is_neg, int index,
	char buffer[],int size, int width, int precision, int flags);
int _writepointer(char buffer[], int index, int flags, int width, int len,
	char padd, char extra_ch, int start_padd);
int is_printable(char a);
int append_hexa_code(char ascii_val, char buffer[], int x);
int is_digit(char a);
long int convert_size_number(long int num1, int size);
long int convert_size_unsgnd(unsigned long int num1, int size);

#endif
