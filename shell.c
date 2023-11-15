#include "main.h"
/**
 * free_argv - Frees the memory allocated for an array of strings.
 * @argv: A pointer to a pointer to an array of strings.
 *
 * This function frees the memory allocated for each string in the array
 * and then frees the array itself. The pointer to the array is set to NULL
 * after freeing to avoid using a dangling pointer.
 */
void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
	*argv = NULL;
}

/**
 * main - entry poin
 * Return: success or failure checker
 */

int main(void)
{
	char *token, *lineptr, **argv;
	char *lineptr_copy = NULL;
	const char *delim = " \n";
	size_t n = 0;
	int i = 0, num_of_tokens = 0;
	ssize_t num_of_chars_read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		num_of_chars_read = getline(&lineptr, &n, stdin);
		if (num_of_chars_read == -1)
			return (0);
		lineptr_copy = malloc(sizeof(char) * num_of_chars_read);
		if (lineptr_copy == NULL)
		{
			return (-1); }
		strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_of_tokens++;
			token = strtok(NULL, delim); }
		num_of_tokens++;
		argv = malloc(sizeof(char *) * num_of_tokens);
		token = strtok(lineptr_copy, delim);
		for (i = 0; token != NULL; i++)
		{argv[i] = malloc(strlen(token) + 1);
			strcpy(argv[i], token);
			token = strtok(NULL, delim); }
		argv[i] = NULL;
		if (strcmp(argv[0], "exit") == 0)
		{
			return (0); }
		execomd(argv); }
	free(lineptr_copy);
	free(lineptr);
	free_argv(argv);
	return (0); }
