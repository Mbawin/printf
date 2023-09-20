#include "main.h"

/************ PRINTS AN UNSIGNED NUMBER ************/
/**
 * print_unsigned_number - Function prints an unsigned number
 * @buffer: Buffer array to handle print
 * @types: List of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of characters printed.
 */
int print_unsigned_number(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[a--] = (number % 10) + '0';
		number /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buffer, precision, flags, size, width));
}

/****** FUNCTION PRINTS UNSIGNED NUMBER IN OCTAL  *********/
/**
 * print_unsigned_num_in_octal - Prints an unsigned number in octal notation
 * @buffer: Buffer array to handle print
 * @types: List of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of characters printed
 */
int print_unsigned_num_in_octal(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{

	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[a--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, precision, flags, size, width));
}
/***** PRINT HEXADECIMAL NUMBER IN LOWER OR UPPER *******/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * Return: Number of characters printed
 */
int print_hexa(char buffer[], va_list types, char map_to[],
	char flag_ch, int precision, int flags, int size, int width)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[a--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, precision, flags, size, width));
}

/********* FUNCTION PRINTS UNSIGNED NUMBER IN HEXADECIMAL ********/
/**
 * print_unsigned_num_in_hexadecimal - Prints an unsigned num in hexadecimal
 * @buffer: Buffer array to handle print
 * @types: List of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of characters printed
 */
int print_unsigned_num_in_hexadecimal(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		precision, 'x', flags, size, width));
}

/**** PRINTS UNSIGNED NUMBER IN UPPER HEXADECIMAL ********/
/**
 * print_upper_hexa - Prints an unsigned number in upper hexadecimal notation
 * @buffer: Buffer array to handle print
 * @types: List of arguments
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: Number of characters printed
 */
int print_upper_hexa(char buffer[], va_list types,
	int precision, int flags, int size, int width)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		precision, 'x', flags, size, width));
}
