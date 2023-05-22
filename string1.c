#include "shell.h"



/**
 * _strcpy- Copies a string
 * @dest: The destination
 * @src: The source
 *
 * Return: Destination pointer
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;

	return (dest);
}



/**
 * _strdup- Duplicates a string
 * @str: The string to duplicate
 *
 * Return: Duplicated string pointer
 */

char *_strdup(const char *str)
{
	int length = 0;

	char *ret;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;

	ret = malloc(sizeof(char) * (length + 1));

	if (!ret)
		return (NULL);

	for (length++; length--;)
		ret[length] = *--str;

	return (ret);
}



/**
 * _puts- Prints an input string
 * @str: String to be printed
 *
 * Return: 0(Success)
 */

void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}



/**
 * _putchar- Writes char c to stdout
 * @c: Char to print
 *
 * Return: On success 1.
 * On error, Errno is set appropriately, abd -1 is returned
 */

int _putchar(char c)
{
	static int i;

	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;

	}

	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
