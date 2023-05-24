#include "shell.h"


/**
 * _myhistory - Show command line, History list, and preceded
 *              with line numbers, that start at 0.
 * @info: The structure that contains potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 0 Always (SUccess)
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - The sets of alias to string
 * @info: Struct of parameter
 * @str: The string alias
 *
 * Return: 1 on error, 0 on Success
 */
int unset_alias(info_t *info, char *str)
{
	char *p, k;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	k = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = k;
	return (ret);
}

/**
 * set_alias - The sets of alias to string
 * @info: The struct of parameter
 * @str: The string alias
 *
 * Return: 1 on error, 0 on Success
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints an alias string
 * @node: The alias node
 *
 * Return: 1 on error, 0 on Success
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - Mimics the man of  builtin
 * @info: Structure contains potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: 0 Always (Success)
 */
int _myalias(info_t *info)
{
	int q = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (q = 1; info->argv[q]; q++)
	{
		p = _strchr(info->argv[q], '=');
		if (p)
			set_alias(info, info->argv[q]);
		else
			print_alias(node_starts_with(info->alias, info->argv[q], '='));
	}

	return (0);
}
