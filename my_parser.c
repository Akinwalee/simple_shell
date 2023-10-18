#include "main.h"

/**
 * parseline - Seperate the input string into individual strings
 *
 * @input: The input string
 * @line: The number of characters read
 * @argv: Argument vector
 *
 * Return: The seperated strings as tokens.
 */

char **parseline(char **argv, char *input, ssize_t line)
{
	char *input_copy = NULL, *token;
	const char *delim = " \n";
	int tokens_num = 0, i = 0;

	if (line == -1)
	{
		free(input);
		return (NULL);
	}
	input_copy = malloc(line + 1);
	if (!input_copy)
	{
		perror("simple_shell: memmory allocation error");
		exit(EXIT_FAILURE);
	}
	strcpy(input_copy, input);

	token = strtok(input, delim);
	if (!token)
	{
		free(input_copy);
		return (NULL);
	}
	while (token)
	{
		tokens_num++;
		token = strtok(NULL, delim);
	}
	tokens_num++;
	argv = malloc(sizeof(char *) * tokens_num);
	token = strtok(input_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(strlen(token) + 1);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(input_copy);
	return (argv);
}
