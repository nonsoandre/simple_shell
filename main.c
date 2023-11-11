#include "main.h"
/**
 * main - entry function
 * @argc: number of arguements
 * @argv: command line values
 * Return: exist point if any error
 */
int main(void)
{
char *token;
char *lineptr;
char *lineptr_coppy = NULL;
const char *delim = " \n";
size_t n = 0;
char **argv;
int i = 0;
int num_of_tokens = 0;
ssize_t num_of_chars_read;

while (1){
printf("$ ");
num_of_chars_read = getline(&lineptr, &n, stdin);

lineptr_coppy = malloc(sizeof(char) * num_of_chars_read);
if (lineptr_coppy == NULL){
        perror("tsh: faile to allocate memory");
        return (-1);
}       
strcpy(lineptr_coppy, lineptr);

if (num_of_chars_read == -1){
printf("Exiting shell... \n");
return (-1);
}
else {
token = strtok(lineptr, delim);
while (token != NULL){
num_of_tokens++;
token = strtok(NULL, delim);
}
num_of_tokens++;

argv = malloc(sizeof(char *) * num_of_tokens);
token = strtok(lineptr_coppy,delim);
 for (i = 0; token != NULL; i++) {

                argv[i] = malloc(strlen(token) + 1);
                strcpy(argv[i], token);
                token = strtok(NULL, delim);

                printf(">>>  %s \n", argv[i]);
            }

argv[i] = NULL;

free(argv);
free(lineptr);
free(lineptr);
}
}
return (0);
}
