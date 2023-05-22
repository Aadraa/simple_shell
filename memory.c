#include "shell.h"

/**
 * bfree- NULLs the address and frees the pointer
 * @ptr: Pointer address to free
 *
 * Return: Free if 1, 0 otherwise.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);

		*ptr = NULL;

		return (1);
	}
	return (0);
}
