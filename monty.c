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
	unsigned int line_n = 0;
	stack_t *head = NULL;
	char *opcode = NULL;
	size_t n;

	vars.file_stream = NULL;
	vars.line = NULL;
	if (ac != 2) /* If not correct # of args. */
	{
		fprintf(stderr, "\033[31mUSAGE: monty file\033[0m\n");
		exit(EXIT_FAILURE);
	}
	vars.file_stream = fopen(av[1], "r"); /* Opens FILE stream. */
	if (!vars.file_stream)
	{
		fprintf(stderr, "\033[31mError: Can't open file %s\033[0m\n",
			av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&vars.line, &n, vars.file_stream) != -1)
	{  /* While reading the line is not -1 */
		line_n++;
		vars.line = remove_new_line(vars.line);
		opcode = strtok(vars.line, " ");
		if (opcode)
			get_monty_code(&head, opcode, line_n);
	}
	free(vars.line);
	free_list(&head);
	fclose(vars.file_stream);
	return (0);
}
