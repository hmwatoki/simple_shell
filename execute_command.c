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
char *path = getenv("PATH");
char *path_copy = strdup(path);
char *dir = strtok(path_copy, ":");

while (dir != NULL)
{
  cmd_path = malloc(strlen(dir) + strlen(args[0]) + 2);
  sprintf(cmd_path, "%s/%s", dir, args[0]);
  if (access(cmd_path, F_OK) == 0)
    break;

  free(cmd_path);
  dir = strtok(NULL, ":");
}

free(path_copy);

if (dir == NULL)
{
fprintf(stderr, "%s: %d: %s: not found\n", "./hsh", 1, args[0]);
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
