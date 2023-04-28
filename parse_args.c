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
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL && i < MAX_ARGS)
    {
        args[i] = strdup(token);
        if (args[i] == NULL)
        {
            return;
        }
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}
