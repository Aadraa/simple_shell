#include "shell.h"

/**
 * list_len- shows length of linked list
 * @h: first node pointer
 *
 * Return: List size
 */

size_t list_len(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		h = h->next;
		j++;
	}

	return (j);
}


/**
 * list_to_strings- returned an array of strings of the list->str
 * @head: Pointer to first node
 *
 * Return: Array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;

	size_t k = list_len(head), j;

	char **strs;

	char *str;

	if (!head || !k)
		return (NULL);

	strs = malloc(sizeof(char *) * (k + 1));

	if (!strs)
		return (NULL);

	for (k = 0; node; node = node->next, k++)
	{
		str = malloc(_strlen(node->str) + 1);

		if (!str)
		{
			for (j = 0; j < k; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[k] = str;
	}

	strs[k] = NULL;
	return (strs);
}



/**
 * print_list- Prints all elements of a list_t linked list
 * @h: Points to first node
 *
 * Return: List size
 */

size_t print_list(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));

		_putchar(':');

		_putchar(' ');

		_puts(h->str ? h->str : "(nil)");

		_puts("\n");

		h = h->next;
		j++;
	}
	return (j);
}



/**
 * node_starts_with- Returns node whose string starts with prefix
 * @node: Pointer to list head
 * @prefix: String to match
 * @c: Next char after prefix to match
 *
 * Return: Match node or null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);

		if (p && ((c == -1) || (*p == c)))
			return (node);

		node = node->next;
	}
	return (NULL);
}



/**
 * get_node_index- Gets the index of a node
 * @head: Point to list head
 * @node: The points to the nade
 *
 * Return: Index of node or -1
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t j = 0;

	while (head)
	{
		if (head == node)
			return (j);

		head = head->next;
		j++;
	}
	return (-1);
}
