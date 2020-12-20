#include "monty.h"
/**
 * pop_h         - Pops the top element of the stack.
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
void pop_h(stack_t **head, unsigned int line_n)
{
	stack_t *top = NULL;

	top = *head;
	if (!top)
	{
		fprintf(stderr,
			"\033[31mL%d: can't pop an empty stack\033[0m\n",
			line_n);
		exit(EXIT_FAILURE);
	}
	*head = top->next;
	free(top);
}
