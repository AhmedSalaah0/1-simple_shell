#include "main.h"
/**
 * read_input - function that read the input
 * @line: entered command
 * @n: len of command
 * Return: an argument
*/
char **read_input(char *line, size_t *n)
{
char *linecp = malloc(sizeof(char) * (*n));
const char *del = " \n";
int num_tks = 0, i;
char *tks, **argv;


if (linecp == NULL)
{
perror("error");
return (NULL);
}
strcpy(linecp, line);
tks = strtok(line, del);
while (tks != NULL)
{
num_tks++;
tks = strtok(NULL, del);
}
num_tks++;
argv = malloc(sizeof(char *) * num_tks);
tks = strtok(linecp, del);
for (i = 0; tks != NULL; i++)
{
argv[i] = malloc(sizeof(char) * strlen(tks));
strcpy(argv[i], tks);
tks = strtok(NULL, del);
}
argv[i] = NULL;
free(linecp);
return (argv);
}
