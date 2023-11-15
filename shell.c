#include "main.h"
/**
 * main - entry poin
 * Return: success or failure checker
 */

int main(void)
{
char *token;
char *lineptr;
char *lineptr_copy = NULL;
const char *delim = " \n";
size_t n = 0;
char **argv;
int i = 0;
int num_of_tokens = 0;
ssize_t num_of_chars_read;
while (1)
{printf("$ ");
num_of_chars_read = getline(&lineptr, &n, stdin);
if (num_of_chars_read == -1)
{printf("Exiting shell... \n");
return (-1); }
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
{printf("Exiting shell... \n");
return (0); }
execomd(argv); }
free(lineptr_copy);
free(lineptr);
return (0); }
