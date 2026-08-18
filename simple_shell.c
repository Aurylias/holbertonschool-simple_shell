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

	while (1)
	{
		p_userInput = prompt();
		if (p_userInput == NULL || strcmp(p_userInput, "") == 0)
			continue;
		create_child(p_userInput, av, env);
	}
	return (0);
}
