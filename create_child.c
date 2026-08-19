#include "simple_shell.h"

/**
* create_child - Create a child and run a command in it
*
* @argv: The list of argument
* @env: The environment
* @shell_name: The name of the program
* @line_number: Current input line number
*
* Return: The exit status of the child or the error code on failure
*/

int create_child(char **argv, char **env, char *shell_name, int line_number)
{
	int status, exit_status = 0;
	pid_t childPid;
	char *command_path = NULL;

	command_path = find_path(argv[0], env);
	if (command_path)
	{
		free(argv[0]);
		argv[0] = command_path;

		childPid = fork();
		if (childPid == -1)
		{
			perror(shell_name);
			return (1);
		}
		if (childPid == 0)
		{

			if (execve(argv[0], argv, env) == -1)
			{
				perror(argv[0]);
				_exit(127); /*127 - Command not found, or found but can not be used*/
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
		}
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", shell_name, line_number, argv[0]);
		exit_status = 127;
	}
	return (exit_status);
}
