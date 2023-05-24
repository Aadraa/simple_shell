#include "shell.h"

/**
 * _myenv - Current environment to be printed
 * @info: The potential arguments that contains struture Used to maintain
 *          constant function prototype.
 * Return: 0 always (Success)
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Gets the value of an environ variable
 * @info: The potential arguments that contains struture Used to maintain
 * @name: env var name
 *
 * Return: Value name
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;

	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Modify an existing environment or
 *             initiliaze a new exiting variable
 * @info: The potential arguments that contains struture Used to maintain
 *        constant function prototype.
 *  Return: 0 always (Success)
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: The potential arguments that contains struture Used to maintain
 *        constant function prototype.
 * Return: 0 always (Success)
 */
int _myunsetenv(info_t *info)
{
	int u;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (u = 1; u <= info->argc; u++)
		_unsetenv(info, info->argv[u]);

	return (0);
}

/**
 * populate_env_list - The populates environment linked list
 * @info: potential arguments that contains struture Used to maintain
 *          constant function prototype.
 * Return: 0 always (Success)
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;

	size_t u;

	for (u = 0; environ[u]; u++)
		add_node_end(&node, environ[u], 0);
	info->env = node;
	return (0);
}
