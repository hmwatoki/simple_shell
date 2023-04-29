#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * handle_fork - handle fork
 * @command: command
 * Return: void
*/
void handle_fork(char **command)
{
pid_t pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execvp(command[0], command);
perror("execvp");
exit(EXIT_FAILURE);
}
}
