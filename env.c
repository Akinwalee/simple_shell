#include "main.h"

/**
 * get_env - Fetches and prints the shell environment variables
 *
 * Return: 0 (Success)
 */

int get_env(void)
{
	char **env;
	char **end = environ;

	while (*end != NULL)
		end++;

	for (env = end - 1; env >= environ; env--)
		printf("%s\n", *env);

	return (0);
}
