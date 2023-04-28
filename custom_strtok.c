#include <stdio.h>
#include <string.h>
#include "shell.h"
/**
 * _strtok - tknize a string
 * @str: string
 * @delim: delimiter
 * Return: tkn
*/
char *_strtok(char *str, const char *delim)
{
char *last_tkn = NULL;
char *tkn;
if (str)
{
last_tkn = str;
}
if (!last_tkn)
{
return (NULL);
}
tkn = last_tkn;
while (*tkn && strchr(delim, *tkn))
{
tkn++;
}
if (!*tkn)
{
last_tkn = NULL;
return (NULL);
}
last_tkn = tkn + 1;
while (*last_tkn && !strchr(delim, *last_tkn))
{
last_tkn++;
}
if (!*last_tkn)
{
last_tkn = NULL;
}
else
{
*last_tkn = '\0';
last_tkn++;
}
return (tkn);
}
