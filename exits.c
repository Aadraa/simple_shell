#include "shell.h"


/**
 **_strncpy - The copies of a string
 *@dest: Location of string to be copied to
 *@src: The origin string
 *@n: The amount of char to be copied
 *Return: The concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int t, d;
	char *s = dest;

	t = 0;
	while (src[t] != '\0' && t < n - 1)
	{
		dest[t] = src[t];
		t++;
	}
	if (t < n)
	{
		d = t;
		while (d < n)
		{
			dest[d] = '\0';
			d++;
		}
	}
	return (s);
}

/**
 **_strncat - The concatenates two strings
 *@dest: The first string
 *@src: The second string
 *@n: The amount of bytes to be used
 *Return: The concatenated of string
 */
char *_strncat(char *dest, char *src, int n)
{
	int t, d;

	char *s = dest;

	t = 0;
	d = 0;
	while (dest[t] != '\0')
		t++;
	while (src[d] != '\0' && d < n)
	{
		dest[t] = src[d];
		t++;
		d++;
	}
	if (d < n)
		dest[t] = '\0';
	return (s);
}

/**
 **_strchr - Finds a char in a string
 *@s: The string to be parsed
 *@c: The char to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
