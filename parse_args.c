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
char *tkn = strtok(input, " ");
int i = 0;
while (tkn != NULL && i < MAX_ARGS)
{
args[i] = strdup(tkn);
if (args[i] == NULL)
{
return;
}
i++;
tkn = strtok(NULL, " ");
}
args[i] = NULL;
}
