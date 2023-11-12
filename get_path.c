#include "main.h"
/**
 * get_path - function that locates he path where the commandd is stored
 * @command_type: the command typed
 * Return: success or failure
 *
 */
char *get_path(char *command_type)
{
char *path;
char *path_copy;
char *path_token;
char *file_path;
int length_of_command;
int length_of_directory;
struct stat buffer;
path = getenv("PATH");
if (path)
{
path_copy = strdup(path);
length_of_command = strlen(command_type);
path_token = strtok(path_copy, ":");
while (path_token != NULL)
{
length_of_directory = strlen(path_token);
file_path = malloc(length_of_command + length_of_directory + 2);
strcpy(file_path, path_token);
strcat(file_path, "/");
strcat(file_path, command_type);
strcat(file_path, "\0");
if (stat(file_path, &buffer) == 0)
{
free(path_copy);
return (file_path);
}
else
{
free(file_path);
path_token = strtok(NULL, ":");
} }
free(path_copy);
if (stat(command_type, &buffer) == 0)
{
return (command_type);
}
return (NULL);
} return (NULL);
}
