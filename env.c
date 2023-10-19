#include "main.h"

/**
 * get_env - Fetches and prints the shell environment variables
 *
 * Return: 0 (Success)
 */

int get_env(void)
{
	char **env;

	for (env = environ; *env; env++)
		printf("%s\n", *env);

	return (0);
}
