#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
 * handle_and_or - function to execute the command
 * @args: arguments passed by the user
 * @status: status of the command
 * @and_or: and or condition
 * Return: void
*/
int handle_and_or(char **args, int status, int and_or)
{
if (and_or == 1 && status == EXIT_SUCCESS)
{
return (execute_command(args));
}
else if (and_or == 2 && status != EXIT_SUCCESS)
{
return (execute_command(args));
}
return (status);
}
