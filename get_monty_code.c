#include "monty.h"
/**
 * get_monty_code - Gets the correct function based on the opcode cmd.
 *
 *    Arguments:
 *      @head:    - Pointer, received by reference, of head of list.
 *    @opcode_s:  - String of the op code, command received
 *                  from the line read.
 *     @line_n:   - Number of line being read.
 *
 *               _____   __  ______  ______  ______
 *              /\  __-./\ \/\  ___\/\  ___\/\  __ \
 *              \ \ \/\ \ \ \ \  __\\ \ \__ \ \ \/\ \
 *               \ \____-\ \_\ \_____\ \_____\ \_____\
 *                \/____/ \/_/\/_____/\/_____/\/_____/
 *                __      ______  ______  ______  ______
 *               /\ \    /\  __ \/\  == \/\  ___\/\___  \
 *               \ \ \___\ \ \/\ \ \  _-/\ \  __\\/_/  /__
 *                \ \_____\ \_____\ \_\   \ \_____\/\_____\
 *                 \/_____/\/_____/\/_/    \/_____/\/_____/
 *
 *                                Dec-2020
 */
void get_monty_code(stack_t **head, char *opcode_s, unsigned int line_n)
{
	unsigned short int i = 0;
	instruction_t op[] = {
		{"push", push}, {"pall", pall},	{"pint", pint},	{"pop", pop_h},
		{"swap", swap},	{"add", added},	{"nop", _nope},	{"sub", _subs},
		{"div", divis},	{"mul", multi},	{"mod", modul},	{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if ((strcmp(op[i].opcode, opcode_s)) == 0)
		{
			op[i].f(head, line_n);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
	{
		fprintf(stderr,
			"\033[31mL%d: unknown instruction %s\033[0m\n",
			line_n, opcode_s);
		free(vars.line);
		fclose(vars.file_stream);
		if (*head || head)
			free_list(head);
		exit(EXIT_FAILURE);
	}
}
