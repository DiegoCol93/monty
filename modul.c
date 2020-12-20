#include "monty.h"
/**
 * modul - Modulus operation of the top two elements
 *         on top of the stack.
 *
 *   Arguments:
 *     @head:    - Pointer head of the list.
 *    @line_n:   - Command line.
 *
 *      _____   __  ______  ______  ______
 *     /\  __-./\ \/\  ___\/\  ___\/\  __ \
 *     \ \ \/\ \ \ \ \  __\\ \ \__ \ \ \/\ \
 *      \ \____-\ \_\ \_____\ \_____\ \_____\
 *       \/____/ \/_/\/_____/\/_____/\/_____/
 *      __      ______  ______  ______  ______
 *     /\ \    /\  __ \/\  == \/\  ___\/\___  \
 *     \ \ \___\ \ \/\ \ \  _-/\ \  __\\/_/  /__
 *      \ \_____\ \_____\ \_\   \ \_____\/\_____\
 *       \/_____/\/_____/\/_/    \/_____/\/_____/
 *
 *                     Dec-2020
 */
void modul(stack_t **head, unsigned int line_n)
{
	stack_t *top = NULL;

	top = *head;
	if (!top || !top->next)
	{
		fprintf(stderr,
			"\033[31mL%d: can't mod, stack too short\033[0m\n",
			line_n);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr,
			"\033[31mL%d: division by zero\033[0m\n",
			line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		top->next->n = top->next->n % top->n;
		*head = top->next;
		free(top);
	}
}
