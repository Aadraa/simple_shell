#include "shell.h"


/**
 * get_environ - The string array copy of our environ to be returned
 * @info: Struture that contains potential arguments used to maintain
 * constant function prototype.
 * Return: 0 (Success)
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Delete an environment variable
 * @info: Struture that contains potential arguments used to maintain
 * constant function prototype.
 * Return: Delete on 1, or 0 otherwise
 * @var: The string envirnment variable property
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t q = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), q);
			q = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		q++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Modify an environment variable or
 * initiliaze a new environment
 * @info: Struture that contains potential arguments used to maintain
 * constant function prototype.
 * @var: The string environment variable property
 * @value: The string environment variable value
 *  Return: 0 (Success)
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
