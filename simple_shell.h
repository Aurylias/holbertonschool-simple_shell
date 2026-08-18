#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <string.h>

void create_child(char **argv, char **env);
char *prompt(void);
char **extracter(char *p_userInput);
void free_argv(char **argv);

#endif
