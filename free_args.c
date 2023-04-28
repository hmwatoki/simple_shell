#include "shell.h"
/**
 * free_args - free args
 * @args: arguments
 * return: void
*/
void free_args(char **args)
{
int i;
for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
args[i] = NULL;
}
}
