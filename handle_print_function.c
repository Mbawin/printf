#include "main.h"
/**
 * handle_print - Function prints an argument based on its type
 * @fmt: Formatted string to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print
 * @precision: Precision specification
 * @flags:  Calculates active flags
 * @size: Size specifier
 * @width: get width
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int precision, int flags, int size, int width)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_chars}, {'s', print_strings}, {'%', print_percentage},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned_number}, {'o', print_unsigned_num_in_octal},
		{'x', print_unsigned_num_in_hexadecimal},
		{'X', print_upper_hexa}, {'p', print_pointers}, {'S', print_non_printable},
		{'r', print_reverse_string}, {'R', print_stringrot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}