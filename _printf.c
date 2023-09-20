#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * print_buffer - A function that prints the subject of the buffer if it exists
 * @buffer: Array of characters
 * @buff_ind: Index at which to add next character, stands for the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/**
 * _printf - A function to print
 * @format: format.
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int precision, flags, size, width, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[a], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			precision = get_precision(format, &a, list);
			flags = get_flags(format, &a);
			size = get_size(format, &a);
			width = get_width(format, &a, list);
			++a;
			printed = handle_print(format, &a, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
