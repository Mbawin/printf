#include "main.h"

/********* FUNCTION PRINTS A REVERSE STRING *************/
/**
 * print_reverse_string - Function prints reverse string.
 * @buffer: Buffer array to handle print
 * @types: List of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of characters printed
 */

int print_reverse_string(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	char *stri;
	int a, count = 0;

	UNUSED(width);
	UNUSED(flags);
	UNUSED(buffer);
	UNUSED(size);

	stri = va_arg(types, char *);

	if (stri == NULL)
	{
		UNUSED(precision);

		stri = ")Null(";
	}
	for (a = 0; str[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char y = str[a];

		write(1, &y, 1);
		count++;
	}
	return (count);
}
/******* FUNCTION PRINTS POINTER *********/
/**
 * print_pointers - Function prints the value of a pointer variable
 * @buffer: Buffer array to handle print
 * @types: List of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of characters printed
 */
int print_pointers(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	char extra_a = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(size);
	UNUSED(width);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_a = '+', length++;
	else if (flags & F_SPACE)
		extra_a = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		flags, width, padd, extra_a, padd_start));
}

/******** FUNCTION PRINT A STRING IN ROT13 ***********/
/**
 * print_stringrot13 - Print a string in rot13.
 * @buffer: Buffer array to handle print
 * @types: List of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of characters printed
 */
int print_stringrot13(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	char x;
	char *stri;
	unsigned int a, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	stri = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(width);

	if (stri == NULL)
		stri = "(AHYY)";
	for (a = 0; stri[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == stri[a])
			{
				x = out[b];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			x = stri[a];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
/********** FUNCTION PRINTS NON PRINTABLE *************/
/**
 * print_non_printable - Prints non printable chars ascii codes in hexa
 * @buffer: Buffer array to handle print
 * @types: List of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of characters printed
 */
int print_non_printable(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	int a = 0, offset = 0;
	char *stri = va_arg(types, char *);

	UNUSED(precision);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(width);

	if (stri == NULL)
		return (write(1, "(null)", 6));

	while (stri[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + offset] = stri[a];
		else
			offset += append_hexa_code(stri[a], buffer, a + offset);

		a++;
	}

	buffer[a + offset] = '\0';

	return (write(1, buffer, a + offset));
}
