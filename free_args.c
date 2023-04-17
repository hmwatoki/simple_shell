#include "shell.h"
#include <stdlib.h>
void freeargs (char **args)
{
int i;
for (i = 0; i < MAX_ARGS; i++)
{
if (args[i] != NULL)
{
free(args[i]);
args[i] = NULL;
}
}
}
