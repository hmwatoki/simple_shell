#include "shell.h"
/**
 * loop_shell - main loop for shell program
 * Description: prompt user, execute commands, and exit on command 'exit'
 */
void loop_shell(void)
{
char *input, *args[MAX_ARGS + 1];
size_t input_len = 0;
int status;
while (1)
{
printf("($) ");
input = NULL;
if (getline(&input, &input_len, stdin) == -1)
{
free(input);
exit(0);
}
input[strlen(input) - 1] = '\0'; /* set last character to null */
if (strcmp(input, "exit") == 0)
{
free(input);
exit(0);
}
else if (strcmp(input, "env") == 0)
{
print_env();
}
else
{
parse_input(input, args);
status = execute_command(args);
if (WIFEXITED(status))
{
int exit_status = WEXITSTATUS(status);
if (exit_status != 0)
{
printf("Error: command exited with status %d\n", exit_status);
}
}
free_args(args);
}
free(input);
}
}
