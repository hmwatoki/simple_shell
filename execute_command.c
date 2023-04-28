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
pid = fork();
if (pid == 0)
{
/* Child process */
if (execvp(args[0], args) == -1)
{
perror("hsh");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Error forking */
perror("hsh");
}
else
{
/* Parent process */
do {waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
printf("\n");
free_args(args);
}
}
