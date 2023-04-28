#ifndef SHELL_H
#define SHELL_H
#define B_SIZE 1024
#define MAX_ARGS 10
#define ARGS_SIZE 128
/*
 * File: shell.h
 * Auth: Hmwatoki & MoreKodhek
 * Description: simple shell header file
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;
void loop_shell(void);
void parse_input(char *input, char **args);
void free_args(char **args);
int execute_command(char **args);
char *find_command_in_path(char *command);
void print_env(void);
char* _strtok(char* str, const char* delim);
#endif
