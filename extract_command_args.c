#include "simple_shell.h"

/**
* extracter - Get the user command, split it and return a array of token
*
* @p_userInput: A pointer to the string to split
*
* Return: A poiter to the array of token or NULL on failure
*/

char **extracter(char *p_userInput)
{
	char **argv = NULL;
	char *token = NULL;
	char delimiter[] = " \t\r\n\a";
	int i = 0, count = 0;
	char *copy = strdup(p_userInput);

	if (!copy)
		return (NULL);

	token = strtok(copy, delimiter);
	while (token)
	{
		count++;
		token = strtok(NULL, delimiter);
	}
	free(copy);

	if (count == 0)
		return (NULL);

	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);

	token = strtok(p_userInput, delimiter);
	while (token)
	{
		argv[i++] = strdup(token);
		token = strtok(NULL, delimiter);
	}
	argv[i] = NULL;

	return (argv);
}
