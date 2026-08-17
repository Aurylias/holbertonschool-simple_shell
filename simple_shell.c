#include "simple_shell.h"

/**
* main - A replica of the linux shell but simpler
*
* @ac: The number of argument passed to main
* @av: The list of argument passed to main
* @env: The environment
*
* Return: 1 on success, 0 on failure
*/

int main(int ac, char **av, char **env)
{
	pid_t childPid;
	char *p_userInput = NULL;
	int status;

	if (ac > 1)
	{
		if (execve(av[1], av, env) == -1)
		{
			perror("On execve()");
			return (1);
		}
		return (0);
	}
	while (1)
	{
		p_userInput = prompt();

		childPid = fork();
		if (childPid == -1)
		{
			error_free("On fork()", p_userInput);
			return (1);
		}
		if (childPid == 0)
		{
			if (execve(p_userInput, av, env) == -1)
			{
				error_free("On execve()", p_userInput);
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(p_userInput);
	return (0);
}
