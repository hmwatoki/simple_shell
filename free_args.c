#include "shell.h"
/**
 * free_args - free args
 * @args: arguments
 * return: void
*/
void free_args(char **args)
{
int i, j;
i = 0;
for (j = 0; j < i; j++)
{
free(args[j]);
}
}
