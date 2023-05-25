#include "main.h"
/**
*
*
*
*/
int unsetenv_builtin(const char* variable) {
    if (unsetenv(variable) != 0) {
        fprintf(stderr, "Failed to unset environment variable.\n");
        return 1;
    }
    return 0;
}
