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
	int last_status = 0, line_number = 0;
	(void)ac;

	while (1)
	{
		p_userInput = prompt(last_status);
		if (p_userInput == NULL)
			continue;
		line_number++;

		argv = extracter(p_userInput);
		free(p_userInput);
		if (!argv)
			continue;

		last_status = create_child(argv, env, av[0], line_number);
		free_argv(argv);
	}
	return (last_status);
}
