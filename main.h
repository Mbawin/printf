#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/****** FUNCTIONS FOR PRINTF*********/

/* Funtions to print chars and strings */
int print_chars(char buffer[], va_list types,
	int precision, int flags, int size, int width);
int print_strings(char buffer[], va_list types,
	int precision, int flags, int size, int width);
int print_percentage(char buffer[], va_list types,
	int precision, int flags, int size, int width);

/* Function to print non printable characters */
int print_non_printable(char buffer[], va_list types,
	int precision, int flags, int size, int width);

/* Function to print memory address */
int print_pointers(char buffer[], va_list types,
	int precision, int flags, int size, int width);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *a);
int get_width(const char *format, int *a, va_list list);
int get_precision(const char *format, int *a, va_list list);
int get_size(const char *format, int *a);

/* Functions to print numbers */
int print_int(char buffer[], va_list types,
	int precision, int flags, int size, int width);
int print_binary(char buffer[], va_list types,
	int precision, int flags, int size, int width);
int print_unsigned_number(char buffer[], va_list types,
	int precision, int flags, int size, int width);
int print_unsigned_num_in_octal(char buffer[], va_list types,
	int precision, int flags, int size, int width);
int print_unsigned_num_in_hexadecimal(char buffer[], va_list types,
	int precision, int flags, int size, int width);
int print_upper_hexa(char buffer[], va_list types,
	int precision, int flags, int size, int width);

int print_hexa(char buffer[], va_list types, char map_to[],
	char flag_ch, int precision, int flags, int size, int width);

/*Function to print string in reverse*/
int print_reverse_string(char buffer[], va_list types,
	int precision, int flags, int size, int width);

/*Function to print a string in rot 13*/
int print_stringrot13(char buffer[], va_list types,
	int precision, int flags, int size, int width);

/* width handler */
int handle_write_chars(char b, char buffer[],
	int precision, int flags, int size, int width);
int write_a_number(int is_negative, int ind, char buffer[],
	int precision, int flags, int size, int width);
int write_nums(int ind, char buffer[],
	int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointers(char buffer[], int ind, int length,
	int flags, int width, char padd, char extra_c, int padd_start);

int write_unsigned(int is_negative, int ind,
	char buffer[],
	int precision, int flags, int size, int width);

/******* UTILITIS *******/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsignd(unsigned long int num, int size);

#endif /* MAIN_H */
