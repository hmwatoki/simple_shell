#include "shell.h"
/**
 * loop_shell - main loop for shell program
 * Description: prompt user, execute commands, and exit on command 'exit'
 */
void loop_shell(void)
{
char *input, *args[MAX_ARGS + 1];
int status;
pid_t pid;
while (1)
{
printf("cisfun$ ");
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
parse_input(input, args);/*parse input*/
pid = fork();/*create child process*/
if (pid == -1)/*if failed print error*/
{
perror("failed to fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)/*check if child process*/
{
if (execve(args[0], args, NULL) == -1)/*execute user command*/
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);/*wait for child process to complete*/
}
free(input);
free_args(args);/*free args*/
}
}
