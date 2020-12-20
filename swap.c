#include "monty.h"
/**
 * swap          - Prints the value at the top of the stack/list.
 *
 *   Arguments:
 *     @head:    - Pointer to head of the list.
 *    @line_n:   - Command line number.
 *
 *     Exit:     - EXIT_FAILURE if there's no stack.
 *          _____   __  ______  ______  ______
 *         /\  __-./\ \/\  ___\/\  ___\/\  __ \
 *         \ \ \/\ \ \ \ \  __\\ \ \__ \ \ \/\ \
 *          \ \____-\ \_\ \_____\ \_____\ \_____\
 *           \/____/ \/_/\/_____/\/_____/\/_____/
 *          __      ______  ______  ______  ______
 *         /\ \    /\  __ \/\  == \/\  ___\/\___  \
 *         \ \ \___\ \ \/\ \ \  _-/\ \  __\\/_/  /__
 *          \ \_____\ \_____\ \_\   \ \_____\/\_____\
 *           \/_____/\/_____/\/_/    \/_____/\/_____/
 *
 *                        Dec-2020
 */
void swap(stack_t **head, unsigned int line_n)
{
	stack_t *top = NULL;

	top = *head;
	if (!top || !top->next)
	{
		fprintf(stderr,
			"\033[31mL%d: can't swap, stack too short\033[0m\n",
			line_n);
		exit(EXIT_FAILURE);
	}
	top = top->next;
	top->prev->next = top->next;
	top->next = top->prev;
	top->prev->prev = top;
	top->prev = NULL;
	*head = top;
}
