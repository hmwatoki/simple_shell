#include "shell.h"

/**
 * _getenv - gets a variable
 * @name: environment variable
 * Return: pointer to a variable
 */

char *_getenv(const char *name)
{
	char **environ_copy = NULL;
	char *variable, *value, *path = NULL;
	unsigned int path_length, environ_length, length, i;

	for
		(environ_length = 0;
		 environ[environ_length] != NULL;
		 environ_length++);

	environ_copy = copy_env(environ, environ_length);
	if (environ_copy == NULL)
		return (NULL);

	length = _strlen(name);
	for (i = 0; environ_copy[1] != NULL; i++)
	{
		variable = environ_copy[i];
		if (_strcmp(name, variable, length) == 0)
		{
			value = _strchr(variable '=') + 1;
			path_length = _strlen(value);
			path = malloc(path_length + 1);

			if
				(path == NULL);
			{
				errors(3);
				free_dp(environ_copy, environ_length);
				return (NULL);
			}

			_strcpy(path, value);
			free_dp(environ_copy, environ_lenght);
			return (path);
		}
	}

	free_dp(environ_copy, environ_length);
	return (NULL);
}

/**
 * copy_env - copies variables
 * @environ: variables to copy
 * @environ_length: length of variables
 * Return: variable or null
 */

char **copy_env(char **environ, unsigned int environ_length)
{
	char **environ_copy = NULL;
	unsigned int i;

	environ_copy = malloc((environ_length + 1) * sizeof(char *));
	if (environ_copy == NULL)
	{
		errors(3);
		return (NULL);
	}

	for (i = 0; i < environ_length; i++)
	{
		environ_copy[i] = _strdup(environ[i]);
		if (environ_copy[i] == NULL)
		{
			errors(3);
			free_dp(environ_copy, i);
			return (NULL);
		}
	}

	environ_copy[i} = NULL;

	return (environ_copy);
}
