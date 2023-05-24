#include "shell.h"

/**
 * interactive - Return true if shell is in interactive mode
 * @info: The struct address
 *
 * Return: 0 otherwise, 1 if in interactive mode
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Checks if char is a delimeter
 * @c: Character to check
 * @delim: Delimeter string
 * Return: 0 if false, 1 if true
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Checks for alphabetic char
 * @c: Inputed char
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts a string to an integer
 * @s: String to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int t, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (t = 0; s[t] != '\0' && flag != 2; t++)
	{
		if (s[t] == '-')
			sign *= -1;

		if (s[t] >= '0' && s[t] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[t] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
