#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
 * parse_input - parse input
 * @input: input
 * @args: args
 * Return: void
*/
void parse_input(char *input, char **args)
{
char *arg = strtok(input, " ");
int i = 0;
while (arg != NULL && i < MAX_ARGS)
{
args[i] = malloc(sizeof(char) * ARGS_SIZE);
if (args[i] == NULL)
{
return;
}
if (strlen(arg) > ARGS_SIZE - 1)
{
return;
}
strncpy(args[i], arg, ARGS_SIZE);
arg = strtok(NULL, " ");
i++;
}
args[i] = NULL;
}
