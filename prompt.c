#include "simple_shell.h"

/**
* get_cwd - Get the current working directory and show only the last two
*
* Return: A pointer to the current directory, otherwise NULL
*/

char *get_cwd(void)
{
	char *token = NULL, *cwdCpy = NULL;
	char cwd[PATH_MAX], buffer[PATH_MAX];
	int i = 0, files = 0;

	getcwd(cwd, sizeof(cwd));

	cwdCpy = strdup(cwd);
	if (!cwdCpy)
		return (NULL);

	token = strtok(cwdCpy, "/");
	while (token)
	{
		files++;
		token = strtok(NULL, "/");
	}

	free(cwdCpy);

	token = strtok(cwd, "/");
	strcpy(buffer, "~/");
	while (token)
	{
		if (i > files - 3)
		{
			strcat(buffer, token);
			strcat(buffer, "/");
		}
		token = strtok(NULL, "/");
		i++;
	}

	return (strdup(buffer));
}

/**
* prompt - Display the prompt
*
* @last_status: Exit status of the last command, used on EOF
*
* Return: 1 on success, otherwise 0
*/

char *prompt(int last_status)
{
	char *p_userInput = NULL;
	char *p_newLine = NULL;
	char *invite_line = NULL;
	size_t length = PATH_MAX;
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		invite_line = get_cwd();
		printf("%s$ ", invite_line);
		free(invite_line);
	}
	if (getline(&p_userInput, &length, stdin) == -1)
	{
		if (interactive)
			printf("\n");
		free(p_userInput);
		exit(last_status);
	}

	/*Trouve le premier \n et retourne son index*/
	p_newLine = strchr(p_userInput, '\n');
	if (p_newLine)
		*p_newLine = '\0';

	return (p_userInput);
}
