#include "simple_shell.h"

/**
* prompt - Display the prompt
*
* Return: 1 on success, otherwise 0
*/

char *prompt(void)
{
	char *p_userInput = NULL;
	char *p_newLine = NULL;
	size_t length = PATH_MAX;
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
		printf("->$ ");
	if (getline(&p_userInput, &length, stdin) == -1)
	{
		if (interactive)
			printf("\n");
		free(p_userInput);
		exit(0);
	}

	/*Trouve le premier \n et retourne son index*/
	p_newLine = strchr(p_userInput, '\n');
	if (p_newLine)
		*p_newLine = '\0';

	return (p_userInput);
}
