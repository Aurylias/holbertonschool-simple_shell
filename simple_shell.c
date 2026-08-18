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
	char *p_userInput = NULL;
	char **argv = NULL;
	(void)ac;
	(void)av;

	while (1)
	{
		p_userInput = prompt();
		if (p_userInput == NULL)
			continue;

		argv = extracter(p_userInput);
		free(p_userInput);
		if (!argv)
			continue;

		create_child(argv, env);
		free_argv(argv);
	}
	return (0);
}
