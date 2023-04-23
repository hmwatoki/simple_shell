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
char *cmd_path;
cmd_path = find_command_in_path(args[0]);
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
