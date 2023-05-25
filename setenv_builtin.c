#include "main.h"
/**
 *setenv_builtin - set environ
 *@variable: environ variable
 *@value: value of var
 *Return: 0 or 1
 */
int setenv_builtin(const char* variable, const char* value) {
    if (setenv(variable, value, 1) != 0) {
        fprintf(stderr, "Failed to set environment variable.\n");
        return 1;
    }
    return 0;
}
