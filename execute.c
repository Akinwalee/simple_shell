#include "main.h"

/**
 * execute - Checks if the entry is empty or not before running thr command
 *
 * @args: The user input
 * @argv: The shell argument vector
 *
 * Return: 1 if the input is empty or return values of the command run.
 */

int execute(char **args, char **argv)
{
	int output;

	if (args[0] == NULL)
		return (1);

	if (!strcmp(args[0], "env"))
	{
		get_env();
		return (0);
	}

	output = execute_command(args, argv);
	return (output);
}
