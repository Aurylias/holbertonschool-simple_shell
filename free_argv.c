#include "simple_shell.h"

/**
* free_argv - Free a NULL terminated array of strings and the array it self
*
* @argv: The array to free
*/

void free_argv(char **argv)
{
	int i;

	if (!argv)
		return;

	for (i = 0; argv[i]; i++)
		free(argv[i]);

	free(argv);
}
