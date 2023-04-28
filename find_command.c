#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
/**
 * find_command_in_path - function to find the command in the PATH
 * @command: the command to find
 * Return: the full path to the command or NULL if not found
 */
char *find_command_in_path(char *command)
{
char *path, *token, *cmd_path = NULL;
if (access(command, X_OK) == 0)
{
cmd_path = command;
}
else
{
path = strdup(getenv("PATH"));
token = strtok(path, ":");
while (token)
{
size_t len = strlen(token) + strlen(command) + 2;
if (cmd_path == NULL)
{
cmd_path = malloc(len);
}
else
{
cmd_path = realloc(cmd_path, len);
}
snprintf(cmd_path, len, "%s/%s", token, command);
if (access(cmd_path, X_OK) == 0)
{
break;
}
token = strtok(NULL, ":");
}
free(path);
}
return (cmd_path);
}
