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
char *token = strtok(input, " ");/*tokenize input*/
int i = 0;
while (token != NULL && i < MAX_ARGS)
{
args[i] = malloc(sizeof(char) * ARGS_SIZE); /*allocate mem for args*/
if (args[i] == NULL)
{
return;
}
if (strlen(token) > ARGS_SIZE - 1)
{
return;
}
strncpy(args[i], token, ARGS_SIZE);/*copy token to args*/
token = strtok(NULL, " ");/*tokenize next input*/
i++;
}
args[i] = NULL;
}
