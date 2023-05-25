#include "main.h"
/**
 * main - entry point
 * @ac: Num of argu.
 * @argv: array of arguments
 * Return: returned 0, or -1 if fail
 */
int main(void) {
    char *line = NULL;
    size_t n = 0;
    char *args[3];

    while (1) {
        printf("$ ");
        if (getline(&line, &n, stdin) == -1) {
            perror("getline error");
            return -1;
        }

        args[0] = strtok(line, " \t\n");
        if (args[0] == NULL)
            continue;
        args[1] = strtok(NULL, " \t\n");
        args[2] = strtok(NULL, " \t\n");

        if (strcmp(args[0], "env") == 0) {
            execute_env();
        } else if (strcmp(args[0], "setenv") == 0) {
            if (args[1] == NULL || args[2] == NULL) {
                fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
                continue;
            }
            if (setenv_builtin(args[1], args[2]) != 0) {
                fprintf(stderr, "Failed to set environment variable.\n");
            }
        } else if (strcmp(args[0], "unsetenv") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "Usage: unsetenv VARIABLE\n");
                continue;
            }
            if (unsetenv_builtin(args[1]) != 0) {
                fprintf(stderr, "Failed to unset environment variable.\n");
            }
        } else {
            execute(args, args);
        }
    }

    free(line);
    return 0;
} 
