#ifndef SHELL_H
#define SHELL_H
#define BUFFER_SIZE 1024
/*
 * File: shell.h
 * Auth: hmwatoki
 * Description: simple shell header file
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
void loop_shell(void);
#endif
