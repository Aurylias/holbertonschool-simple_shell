#include "simple_shell.h"

/**
* find_path - Looks for files in the PATH
*
* @filename: The name of the file to search
* @env: The environment
*
* Return: A pointer to the path, otherwise NULL
*
*/

char *find_path(char *filename, char **env)
{
	char *path = NULL, *token = NULL;
	char buffer[PATH_MAX];
	int i;

	if (strchr(filename, '/'))
	{
		if (access(filename, X_OK) == 0)
			return (strdup(filename));
		return (NULL);
	}
	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = strdup(env[i] + 5);
			if (!path)
				return (NULL);
			break;
		}
	}
	if (!path)
		return (NULL);

	if (path[0] == '\0')
	{
		free(path);
		strcpy(buffer, "./");
		strcat(buffer, filename);
		if (access(buffer, X_OK) == 0)
			return (strdup(buffer));
		return (NULL);
	}
	token = strtok(path, ":");
	while (token)
	{
		strcpy(buffer, token);
		strcat(buffer, "/");
		strcat(buffer, filename);
		if (access(buffer, X_OK) == 0)
		{
			free(path);
			return (strdup(buffer));
		}
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
