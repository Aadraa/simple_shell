#include "shell.h"



/**
 * is_chain- Run if current character in buffer is a chain delimeter
 * @info: Structure parameter
 * @buf: Buffer character
 * @p: Buf current position address
 *
 * Return: Chain delimeter is 1, 0 otherwise
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t q = *p;

	if (buf[q] == '|' && buf[q + 1] == '|')
	{
		buf[q] = 0;

		q++;

		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[q] == '&' && buf[q + 1] == '&')
	{
		buf[q] = 0;
		q++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[q] == ';') /* found end of this command */
	{
		buf[q] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
	return (0);
	*p = q;
	return (1);
}



/**
 * check_chain- Checks we should continue chaining based on last status
 * @info: Structure parameter
 * @buf: Character buffer
 * @p: Buf current starting position
 * @i: Buf starting position
 * @len: Buf length
 *
 * Return: 0(Success)
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t q = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			q = len;
		}

	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			q = len;
		}
	}
	*p = q;
}



/**
 * replace_alias- Replaces an aliases in the tokenized string
 * @info: Structure of the parameter
 *
 * Return: Replace if 0, otherwise 1
 */

int replace_alias(info_t *info)
{
	int k;

	list_t *node;

	char *p;

	for (k = 0; k < 10; k++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}



/**
 * replace_vars- Replaces vars in the tokenized string
 * @info: Structure of the parameter
 *
 * Return: Replaced if 0, otherwise 1
 */

int replace_vars(info_t *info)
{
	int k = 0;
	list_t *node;

	for (k = 0; info->argv[k]; k++)
	{
		if (info->argv[k][0] != '$' || !info->argv[k][1])
			continue;
		if (!_strcmp(info->argv[k], "$?"))
		{
			replace_string(&(info->argv[k]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[k], "$$"))
		{
			replace_string(&(info->argv[k]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[k][1], '=');
		if (node)
		{
			replace_string(&(info->argv[k]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[k], _strdup(""));
	}
	return (0);
}



/**
 * replace_string- String is replaced
 * @old: Old string address
 * @new: String is new
 *
 * Return: Replaced if 0, otherwise 1
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
