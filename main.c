#include "monty.h"
#define BUFFER_SIZE 1024

void process_file(FILE *file);

/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of arguments.
 * @argv: The arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, BUFFER_SIZE, file) != NULL)
    {
        unsigned int line_number = 0;
        char *opcode = NULL;
        line_number++;
        opcode = strtok(line, " \n\t");
        if (opcode && opcode[0] != '#')
        {
            execute_opcode(opcode, &line, line_number);
        }
    }

    free(line);
    fclose(file);
    return (EXIT_SUCCESS);
}
