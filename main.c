#include "main.h"

extern char **environ;
/**
 * main - the entry point to the shell
 * Return: returns 0 if success
 */
int main(void)
{
char *lineptr = NULL;
size_t n = 0;
char **env = environ;
while (1)
{
printf("$ ");
ssize_t num_of_chars_read = getline(&lineptr, &n, stdin);
if (num_of_chars_read == -1)
{
printf("Exiting shell... \n");
free(lineptr);
return (-1); }
char *argv[MAX_ARGUMENTS];
int num_tokens = tokenize_line(lineptr, " \n", argv);
if (num_tokens > 0)
{
if (strcmp(argv[0], "exit") == 0)
{
printf("Exiting shell... \n");
free(lineptr);
return (0);
}
else if (strcmp(argv[0], "env") == 0)
{
//char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++; }
}
else
{
execomd(argv);
} }
free(lineptr);
lineptr = NULL;
}
return (0);
}
