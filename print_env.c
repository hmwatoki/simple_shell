#include "shell.h"
#include <stdio.h>
#include <unistd.h>
/**
 * print_env - function to print env
 * Description: print env
 * Return: void
*/
void print_env(void)
{
int i;
if (environ == NULL)
{
fprintf(stderr, "Error: environ variable is null\n");
return;
}
for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}
