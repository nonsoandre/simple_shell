#include "main.h"

void execomd(char **argv){
char *command_typed = NULL;

if (argv){
command_typed = argv[0];

if (execve(command_typed, argv, NULL) == -1){
	perror("Error:");
};
}
}
