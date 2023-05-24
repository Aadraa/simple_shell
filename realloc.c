#include "shell.h"



/**
 * _memset- Fills memory with a constant byte
 * @s: Pointer to the memory area
 * @b: Byte to fill *s with
 * @n: Total amount of bytes to be filled
 * Return: (s) A pointer to the memory area S
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int p;

	for (p = 0; p < n; p++)
		s[p] = b;

	return (s);
}



/**
 * ffree- Frees a string of strings
 * @pp: String of strings
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;

	while (*pp)
		free(*pp++);

	free(a);
}



/**
 * _realloc- Reallocates a block of memory
 * @ptr: Previous malloc'ated block of pointer
 * @old_size: Previous block byte size
 * @new_size: New block byte size
 *
 * Return: pointer to da ol'block nameen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
		return (free(ptr), NULL);

	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);

	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;

	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
