#include "main.h"

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of characters.
 * @a: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int a)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[a++] = '\\';
	buffer[a++] = 'x';

	buffer[a++] = map_to[ascii_code / 16];
	buffer[a] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a character is a digit
 * @b: Char to be evaluated
 *
 * Return: 1 if b is a digit, 0 otherwise
 */
int is_digit(char b)
{
	if (b >= '0' && b <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @number: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of number
 */
long int convert_size_number(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * convert_size_unsignd - Casts number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsignd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * is_printable - Checks if a character is printable
 * @b: Char to be evaluated.
 *
 * Return: 1 if b is printable, 0 otherwise
 */
int is_printable(char b)
{
	if (b >= 32 && b < 127)
		return (1);

	return (0);
}
