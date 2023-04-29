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
int execute_command(char **args)
{
int status = 0;
int i = 0;
int and_or = 0;
char *command[MAX_ARGS + 1] = {NULL};
while (args[i] != NULL)
{
if (strcmp(args[i], "&&") == 0)
{
and_or = 1;
break;
}
else if (strcmp(args[i], "||") == 0)
{
and_or = 2;
break;
}
command[i] = args[i];
i++;
}
handle_fork(command);
wait(&status);
return (handle_and_or(args + i + 1, status, and_or));
}
