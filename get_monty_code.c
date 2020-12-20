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
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

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
		exit(EXIT_FAILURE);
	}
}