#include "shell.h"
/**
 * check_exit_status - check exit status
 * @status: exit status
 * Return: void
*/
void check_exit_status(int status)
{
if (WIFEXITED(status))
{
int exit_status = WEXITSTATUS(status);
if (exit_status != 0)
{
printf("Error: command exited with status %d\n", exit_status);
}
}
}
