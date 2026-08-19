#include "simple_shell.h"

/**
 * exit_shell - exit the shell
 *
 * @last_status: exit status of the last command
 * @p_userInput: pointer to the prompt of the user
 */

void exit_shell(int last_status, char *p_userInput)
{
	free(p_userInput);
	exit(last_status);
}

/**
 * print_env - print the environment
 *
 * @env: the environment
 */

void print_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);
}
