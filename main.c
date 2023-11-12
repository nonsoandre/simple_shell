#include "main.h"

extern char **environ;
int main(void)
{
    char *lineptr = NULL;
    size_t n = 0;

    while (1) {
        printf("$ ");
        ssize_t num_of_chars_read = getline(&lineptr, &n, stdin);
        if (num_of_chars_read == -1) {
            printf("Exiting shell... \n");
            free(lineptr);
            return (-1);
        }

        // Call the tokenization function to handle tokenization
        char *argv[MAX_ARGUMENTS];
        int num_tokens = tokenize_line(lineptr, " \n", argv);

        if (num_tokens > 0) {
            if (strcmp(argv[0], "exit") == 0) {
                printf("Exiting shell... \n");
                free(lineptr);
                return (0);
            }
            else if (strcmp(argv[0], "env") == 0) {
                // Print the current environment
                char **env = environ;
                while (*env != NULL) {
                    printf("%s\n", *env);
                    env++;
                }
            }
            else {
                execomd(argv);
            }
        }

        // Free memory allocated by getline
        free(lineptr);
        lineptr = NULL;
    }

    return (0);
}

