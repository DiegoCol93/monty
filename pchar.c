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
void pch(stack_t **head, unsigned int line_n)
{
	stack_t *top = NULL;

	top = *head;
	if (!top)
	{
		fprintf(stderr,
			"\033[31mL%d: can't pchar, stack empty\033[0m\n",
			line_n);
		free(vars.line);
		fclose(vars.file_stream);
		if (*head || head)
			free_list(head);
		exit(EXIT_FAILURE);
	}
	if (top->n < 0 || top->n > 127)
	{
		fprintf(stderr,
			"\033[31mL%d: can't pchar, value out of range\033[0m\n",
			line_n);
		free(vars.line);
		fclose(vars.file_stream);
		if (*head || head)
			free_list(head);
		exit(EXIT_FAILURE);
	}
	putchar(top->n);
	putchar(10);
}
