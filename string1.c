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
	int k = 0;

	if (dest == src || src == 0)
		return (dest);

	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = 0;

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
	int distance = 0;

	char *ret;

	if (str == NULL)
		return (NULL);

	while (*str++)
		distance++;

	ret = malloc(sizeof(char) * (distance + 1));

	if (!ret)
		return (NULL);

	for (distance++; distance--;)
		ret[distance] = *--str;

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
	int k = 0;

	if (!str)
		return;

	while (str[k] != '\0')
	{
		_putchar(str[k]);
		k++;
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
	static int k;

	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(1, buf, k);
		k = 0;

	}

	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}
