#include "simple_shell.h"

/**
* create_child - Create a child and run a command in it
*
* @p_userInput: The command to run
* @argv: The list of argument
* @env: The environment
*/

void create_child(char* p_userInput, char **argv, char **env)
{
	int status;
	pid_t childPid;

	childPid = fork();
	if (childPid == -1)
	{
		perror(p_userInput);
		return;
	}
	if (childPid == 0)
	{
		if (execve(p_userInput, argv, env) == -1)
		{
			perror(p_userInput);
			free(p_userInput);
			_exit(127); /*127 - Command not found, or found but can not be used*/
		}
	}
	else
	{
		wait(&status);
	}

	free(p_userInput);
}
