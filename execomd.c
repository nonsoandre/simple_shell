#include "main.h"

/**
 * execomd - function to execuse the command typed
 * @argv: an array of the comand line arguments
 */
void execomd(char **argv)
{
char *command_typed = NULL;
char *final_command = NULL;
char *envp[] = { NULL };
int status;
if (argv)
{
command_typed = argv[0];
final_command = get_path(command_typed);
if (final_command)
{
pid_t pid = fork();
if (pid == 0)
{
if (execve(final_command, argv, envp) == -1)
{
perror("Error");
exit(1);
}
}
else if (pid < 0)
perror("Fork failed");
else
wait(&status);
}
else
{
fprintf(stderr, "hsh: %d: %s: not found\n", 1, argv[0]);
}
}
}

