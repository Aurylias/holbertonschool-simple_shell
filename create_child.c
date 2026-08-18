#include "simple_shell.h"

/**
* create_child - Create a child and run a command in it
*
* @argv: The list of argument
* @env: The environment
*/

void create_child(char **argv, char **env)
{
	int status;
	pid_t childPid;
	char *command_path = NULL;

	command_path = find_path(argv[0], env);
	if (command_path)
	{
		argv[0] = command_path;
		free(command_path);

		childPid = fork();
		if (childPid == -1)
		{
			perror(argv[0]);
			return;
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
		}
	}
	else
		perror(argv[0]);
}
