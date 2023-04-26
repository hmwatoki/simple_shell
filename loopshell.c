#include "shell.h"
/**
 * loop_shell - main loop for shell program
 * Description: prompt user, execute commands, and exit on command 'exit'
 */
void loop_shell(void)
{
char *input, *args[MAX_ARGS + 1];
while (1)
{
printf("($) ");
input = malloc(sizeof(char) * B_SIZE);/*allocate mem for input*/
if (fgets(input, B_SIZE, stdin) == NULL)
{
free(input);
exit(0);
}
input[strlen(input) - 1] = '\0';/*set last character to null*/
if (strcmp(input, "exit") == 0)/**check if input = exit if so quit shell*/
{
free(input);
exit(0);
}
else if (strcmp(input, "env") == 0)
{
print_env();/*prints environment variables*/
}
else
{
parse_input(input, args);/*parse input*/
execute_command(args);
free_args(args);/*free args*/
}
free(input);
}
}
