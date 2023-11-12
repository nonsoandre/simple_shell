#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_ARGUMENTS 100
void execomd(char **argv);
char *get_path(char *command_type);
int tokenize_line(char *line, const char *delim, char **argv);
#endif
