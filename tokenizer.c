#include "main.h"
int tokenize_line(char *line, const char *delim, char **argv) {
    char *token;
    int num_of_tokens = 0;

    token = strtok(line, delim);
    while (token != NULL) {
        num_of_tokens++;
        argv[num_of_tokens - 1] = malloc(strlen(token) + 1);
        if (argv[num_of_tokens - 1] == NULL) {
            perror("tsh: failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        strcpy(argv[num_of_tokens - 1], token);
        token = strtok(NULL, delim);
    }
    argv[num_of_tokens] = NULL;

    return num_of_tokens;
}

