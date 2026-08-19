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
#include <errno.h>

int create_child(char **argv, char **env, char *shell_name, int line_number);
char *prompt(int last_status);
char **extracter(char *p_userInput);
void free_argv(char **argv);
char *find_path(char *filename, char **env);

#endif
