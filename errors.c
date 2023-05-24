#include "shell.h"


/**
 * _eputs - Prints an input string
 * @str: The string to be printed
 *
 * Return: 0 (Success)
 */
void _eputs(char *str)
{
	int p = 0;

	if (!str)
		return;
	while (str[p] != '\0')
	{
		_eputchar(str[p]);
		p++;
	}
}

/**
 * _eputchar - Writes the char c to stderr
 * @c: The char to print
 *
 * Return: 1 on success.
 * On error, errno is set and -1 is returned.
 */

int _eputchar(char c)
{
	static int p;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || p >= WRITE_BUF_SIZE)
	{
		write(2, buf, p);
		p = 0;
	}
	if (c != BUF_FLUSH)
		buf[p++] = c;
	return (1);
}

/**
 * _putfd - The char c to given fd is written
 * @c: The Print char
 * @fd: The File descriptor to write to
 *
 * Return: 1 on success.
 * On error, errno is set, and -1 is returned.
 */

int _putfd(char c, int fd)
{
	static int p;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || p >= WRITE_BUF_SIZE)
	{
		write(fd, buf, p);
		p = 0;
	}
	if (c != BUF_FLUSH)
		buf[p++] = c;
	return (1);
}

/**
 * _putsfd - The input string to be printed
 * @str: The string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: Chars put numbers
 */
int _putsfd(char *str, int fd)
{
	int p = 0;

	if (!str)
		return (0);
	while (*str)
	{
		p += _putfd(*str++, fd);
	}
	return (p);
}
