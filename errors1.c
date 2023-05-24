#include "shell.h"


/**
 * _erratoi - Converting a string to an integer
 * @s: String to be converted
 * Return: The converted number otherwise -1 on error,
 *        0 if no numbers in string
 */
int _erratoi(char *s)
{
	int p = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (p = 0;  s[p] != '\0'; p++)
	{
		if (s[p] >= '0' && s[p] <= '9')
		{
			result *= 10;
			result += (s[p] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - Prints an error message
 * @info: The parameter and return info structure
 * @estr: The string containing specified error type
 * Return: The converted number otherwise -1 on error,
 *        0 if no numbers in string
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - The decimal (integer) number (base 10) function is printed
 * @input: The inputed number
 * @fd: Filedescriptor to write to
 *
 * Return: The number of char printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int p, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (p = 1000000000; p > 1; p /= 10)
	{
		if (_abs_ / p)
		{
			__putchar('0' + current / p);
			count++;
		}
		current %= p;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - The converter function, a clone of itoa
 * @num: Number
 * @base: The base
 * @flags: Argument flags
 *
 * Return: String
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - The instance of '#' with '\0' function is first replaced
 * @buf: The string to modify address
 *
 * Return: 0 (Success)
 */
void remove_comments(char *buf)
{
	int p;

	for (p = 0; buf[p] != '\0'; p++)
		if (buf[p] == '#' && (!p || buf[p - 1] == ' '))
		{
			buf[p] = '\0';
			break;
		}
}
