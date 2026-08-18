#include "simple_shell.h"

/**
* commandToAv - Get the user command, split it and return a array of token
*
* @line: A pointer to the string to split
*
* Return: A poiter to the array of token or NULL on failure
*/

char **extracter(char *line)
{
	char *token = NULL;
	char *lineCpy = NULL;
	char **tokens = NULL;
	int i = 0, words = 0;
	/*Create a copy of line*/
	lineCpy = strdup(line);
	if (!lineCpy)
		return (NULL);
	/*Create the first token*/
	token = strtok(lineCpy, " ");
	while (token != NULL)
	{
		words++;
		token = strtok(NULL, " ");
	}
	/*Create an array that match the size of line*/
	tokens = malloc(sizeof(char *) * (words + 1));
	if (!tokens)
		return (NULL);
	tokens[words] = NULL;
	/*Recreate the first token*/
	free(lineCpy);
	lineCpy = strdup(line);
	if (!lineCpy)
		return (NULL);
	token = strtok(lineCpy, " ");
	/*Loop through the tokens and add them in the array*/
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
			return (NULL);
		token = strtok(NULL, " ");
		i++;
	}

	free(lineCpy);
	return (tokens);
}
