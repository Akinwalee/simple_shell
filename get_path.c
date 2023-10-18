#include "main.h"

/**
 * path - Handles PATH
 * @command: The command whose full path is to be retrieved
 * Return: The full path of @command (Success). NULL otherwise.
 */

char *path(char *command)
{
	char *path, *path_copy, *token, *file_path;
	int dir_len, command_len;
	struct stat buffer;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token)
	{
		dir_len = strlen(token);
		command_len = strlen(command);
		file_path = malloc(dir_len + command_len + 2);
		strcpy(file_path, token);
		strcat(file_path, "/");
		strcat(file_path, command);
		file_path[dir_len + command_len + 1] = '\0';
		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			token = strtok(NULL, ":");
		}
	}
	free(path_copy);
	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	return (NULL);
}
