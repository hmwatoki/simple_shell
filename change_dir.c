#include "shell.h"
/**
 * change_directory - change directory
 * @dir: directory
 * Return: void
*/
void change_directory(char *dir)
{
char *new_pwd, *cwd;
if (dir[0] == '\0')
{
dir = getenv("HOME");
}
else if (strcmp(dir, "-") == 0) /* change to home directory */
{
dir = getenv("OLDPWD");
}
cwd = malloc(sizeof(char) * PATH_MAX);
getcwd(cwd, PATH_MAX);
setenv("OLDPWD", cwd, 1);
free(cwd);
if (chdir(dir) != 0)
{
perror("cd");
}
new_pwd = malloc(sizeof(char) * PATH_MAX);
getcwd(new_pwd, PATH_MAX);
setenv("PWD", new_pwd, 1);
free(new_pwd);
}
