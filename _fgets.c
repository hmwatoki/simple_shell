#include <stdio.h>
#include "shell.h"
/**
 * _fgets - get input from user
 * @str: pointer to string
 * @n: size of string
 * @stream: pointer to stream
 * Return: pointer to string
*/
char *_fgets(char *str, int n, FILE *stream)
{
int i;
char c;
for (i = 0; i < n - 1 && (c = fgetc(stream)) != EOF && c != '\n'; i++)
{
str[i] = c;
}
str[i] = '\0';
if (c == '\n' || i == n - 1)
{
return (str);
}
if (i == 0 && c == EOF)
{
return (NULL);
}
while (c != EOF && c != '\n')
{
c = fgetc(stream);
}
return (str);
}
