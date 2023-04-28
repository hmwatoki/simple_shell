#include <stdlib.h>
#include <string.h>
/**
 * execute_exit_command - execute exit command
 * @input: input
 * Return: void
*/
void execute_exit_command(char *input)
{
int exit_status = atoi(input + 5);
free(input);
exit(exit_status);
}
