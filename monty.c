#include "monty.h"
/**
 * main         - Main entry point of
 *
 * Arguments:
 *    @ac:      - Arguments count, should always be 2.
 *    @av:      - Arguments array, name of the file.
 *
 *  Return:     - 0.
 *        _____   __  ______  ______  ______
 *       /\  __-./\ \/\  ___\/\  ___\/\  __ \
 *       \ \ \/\ \ \ \ \  __\\ \ \__ \ \ \/\ \
 *        \ \____-\ \_\ \_____\ \_____\ \_____\
 *         \/____/ \/_/\/_____/\/_____/\/_____/
 *         __      ______  ______  ______  ______
 *        /\ \    /\  __ \/\  == \/\  ___\/\___  \
 *        \ \ \___\ \ \/\ \ \  _-/\ \  __\\/_/  /__
 *         \ \_____\ \_____\ \_\   \ \_____\/\_____\
 *          \/_____/\/_____/\/_/    \/_____/\/_____/
 *
 *                        Dec-2020
 */
int main(int ac, char **av)
{
	char *opcode = NULL, *line = NULL;
	unsigned int line_n = 0;
	stack_t *head = NULL;
	FILE *f_stream;
	size_t n;

	vars.file_stream = NULL;
	vars.line = NULL;
	if (ac != 2) /* If not correct # of args. */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_stream = fopen(av[1], "r"); /* Opens FILE stream. */
	if (!f_stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n",
			av[1]);
		exit(EXIT_FAILURE);
	}
	vars.file_stream = f_stream;
	while (getline(&line, &n, f_stream) != -1)
	{  /* While reading the line is not -1 */
		line_n++;
		line[strlen(line) - 1] = '\0';
		vars.line = line;
		if (!vars.line)
			continue;
		opcode = strtok(line, " ");
		if (opcode)
		{
			if (opcode[0] == '#')
				continue;
			get_monty_code(&head, opcode, line_n);
		}
	}
	free(line);
	free_list(&head);
	fclose(vars.file_stream);
	exit(EXIT_SUCCESS);
}
