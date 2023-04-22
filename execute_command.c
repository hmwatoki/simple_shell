#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * execute_command - function to execute the command
 * @args: arguments passed by the user
 * Return: void
 */
void execute_command(char **args)
{
pid_t pid;
int status;
char *path, *token;
char *cmd_path = NULL;
if (access(args[0], X_OK) == 0)
{
cmd_path = args[0];
}
else
{
path = strdup(getenv("PATH"));
token = strtok(path, ":");
while (token)
{
size_t len = strlen(token) + strlen(args[0]) + 2;
cmd_path = malloc(len);
snprintf(cmd_path, len, "%s/%s", token, args[0]);
if (access(cmd_path, X_OK) == 0)
{
break;
}
free(cmd_path);
cmd_path = NULL;
token = strtok(NULL, ":");
}
free(path);
}
if (!cmd_path)
{
printf("%s: command not found\n", args[0]);
return;
}
pid = fork();
if (pid == -1)
{
perror("failed to fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(cmd_path, args, NULL) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
free(cmd_path);
}
