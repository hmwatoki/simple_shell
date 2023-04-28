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
pid_t pid;
int status;
pid = fork();
if (pid == 0) /* child process */
{
execvp(args[0], args); /* execute command */
/* If we reach this point, execvp has failed */
printf("Error: command not found\n");
exit(1);
}
else if (pid < 0) /* fork failed */
{
printf("Error: fork failed\n");
exit(1);
}
else /* parent process */
{
wait(&status); /* wait for child process to finish */
return (status);
}
}
