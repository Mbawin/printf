#include "main.h"

/************* PRINTS A STRING ***************/
/**
 * print_string - Prints a string
 * @buffer: Buffer array to handle print
 * @types: List a of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of chars printed
 */
int print_string(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	int length = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(width);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************ PRINTS PERCENTAGE SIGN *****************/
/**
 * print_percent - Prints percentage sign
 * @buffer: Buffer array to handle print
 * @types: List a of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of chars printed
 */
int print_percent(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(width);
	return (write(1, "%%", 1));
}
/************ PRINTS A CHARACTER ************/
/**
 * print_char - Prints a character
 * @buffer: Buffer array to handle print
 * @types: List a of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: Width
 * Return: Number of chars printed
 */
int print_char(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	char b = va_arg(types, int);

	return (handle_write_chars(b, buffer, precision, flags, size, width));
}
/************** PRINTS A BINARY ****************/
/**
 * print_binary - Function prints an unsigned number
 * @buffer: Buffer array to handle print
 * @types: List a of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Numbers of char printed.
 */
int print_binary(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	unsigned int a, b, c, sum;
	unsigned int d[32];
	int count;

	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(width);

	a = va_arg(types, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	d[0] = a / b;
	for (c = 1; c < 32; c++)
	{
		b /= 2;
		d[c] = (a / b) % 2;
	}
	for (c = 0, sum = 0, count = 0; c < 32; c++)
	{
		sum += d[c];
		if (sum || c == 31)
		{
			char y = '0' + d[c];

			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
/********** PRINTS AN INTEGER **************/
/**
 * print_int - Function prints an integer
 * @buffer: Buffer array to handle print
 * @types: List a of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of chars printed
 */
int print_int(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(types, long int);
	unsigned long int num;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)m;

	if (m < 0)
	{
		num = (unsigned long int)((-1) * m);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_a_number(is_negative, a, buffer, precision, flags, size, width));
}
