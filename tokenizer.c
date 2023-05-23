#include "shell.h"


/**
 * **strtow- Words are spilt into strings. Repeat delimiters are ignored
 * @str: Input string
 * @d: Delimeter string
 * Return: Array of strings pointer, or NULL on failure
 */


char **strtow(char *str, char *d)
{
	int m, o, k, t, numwords = 0;

	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (m = 0; str[m] != '\0'; m++)
		if (!is_delim(str[m], d) && (is_delim(str[m + 1], d) || !str[m + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));

	if (!s)
		return (NULL);
	for (m = 0, o = 0; o < numwords; o++)
	{
		while (is_delim(str[m], d))
		m++;
		k = 0;
		while (!is_delim(str[m + k], d) && str[m + k])
			k++;
		s[o] = malloc((k + 1) * sizeof(char));

		if (!s[o])
		{
			for (k = 0; k < o; k++)
				free(s[k]);

			free(s);
			return (NULL);
		}
		for (t = 0; t < k; t++)
			s[o][m] = str[m++];
		s[o][m] = 0;
	}
	s[o] = NULL;
	return (s);
}


/**
 * **strtow2- Words is split in strings
 * @str: The input string
 * @d: The delimeter
 * Return: Array of strings pointer, or NULL on failure
 */

char **strtow2(char *str, char d)
{
	int m, a, k, e, numwords = 0;

	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (m = 0; str[m] != '\0'; m++)
		if ((str[m] != d && str[m + 1] == d) ||
				(str[m] != d && !str[m + 1]) || str[m + 1] == d)
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (m = 0, a = 0; a < numwords; a++)
	{
		while (str[m] == d && str[m] != d)
		m++;
		k = 0;
		while (str[m + k] != d && str[m + k] && str[m + k] != d)
			k++;

		s[a] = malloc((k + 1) * sizeof(char));
		if (!s[a])
		{
			for (k = 0; k < a; k++)
				free(s[k]);

			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[a][m] = str[m++];
		s[a][m] = 0;
	}
	s[a] = NULL;
	return (s);
}
