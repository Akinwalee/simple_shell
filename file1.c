#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * main - Entry point
 * @argc: the number of argument
 * @argv: array of argument
 * Return: 0 (Success) or 1 (Error)
 */

int main(int argc, char **argv)
{
	ssize_t line;
	char *input = NULL, **args;
	size_t buffer = 0;
	int i, ex;
	(void)argc;
	(void)argv;

	while (1)
	{
		input = NULL;
		line = getline(&input, &buffer, stdin);

		if (line == -1)
		{
			free(input);
			break;
		}
		args = parseline(argv, input, line);
		if (args)
		{
			if (!(strcmp(args[0], "exit")))
			{
				free(input);
				for (i = 0; args[i] != NULL; i++)
					free(args[i]);
				free(args);
				break;
			}
			ex = execute(args, argv);
			free(input);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			args  = NULL;
			if (ex)
				return (127);
		}
	}
	return (0);
}
