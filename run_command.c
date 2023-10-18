#include "main.h"
#include <stdio.h>

/**
 * execute_command - Executes the command entered by the user
 *
 * @args: Variable storing the command
 * @argv: The shell argument vector
 *
 * Return: 0 (Success) or 1 (Failure)
 */

int execute_command(char **args, char **argv)
{
	pid_t pid;
	int status = 0;
	char *command;
	char *full_path;


	pid = fork();
	if (pid == -1)
	{
		return (1);
	}
	else if (pid == 0)
	{
		command = args[0];

		full_path = path(command);
		if (full_path == NULL)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
		}
		execve(full_path, args, NULL);

		free(full_path);
		return (1);
	}
	else
	{
		wait(&status);


		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			/**exit(127);*/
		}
		return (WEXITSTATUS(status));
	}
}

