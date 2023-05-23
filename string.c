#include "shell.h"


/**
 * _strlen- Returns the string length
 * @s: The string whose length to check
 *
 * Return: Integer length of string
 */

int _strlen(char *s)
{
	int k = 0;

	if (!s)
		return (0);

	while (*s++)
		k++;

	return (k);
}



/**
 * _strcmp- Performs lexicogarphic comparison of two strangs.
 * @s1: First strang
 * @s2: Second strang
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}



/**
 * starts_with- Confirms needle starts with haystack
 * @haystack: String to search
 * @needle: The substring to find
 *
 * Return: Address of next character of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}



/**
 * _strcat- Concatenates two strings
 * @dest: Buffers destination
 * @src: Buffers source
 *
 * Return: Pointer to destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
