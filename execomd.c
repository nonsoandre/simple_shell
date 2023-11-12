#include "main.h"
/**
 * execomd - function to execute thr commands
 * @argv: array of arguments
 *
 */
void execomd(char **argv)
{
char *command_typed = NULL;
char *final_command = NULL;
char *envp[] = { NULL };
if (argv)
{
command_typed = argv[0];
final_command = get_path(command_typed);

if (final_command)
{
if (execve(final_command, argv, envp) == -1)
{
perror("Error");
}
}
else
{
perror("Command not found");
}
}
}

