#include "monty.h"
/**
 * pall - Prints a doubly linked list stack.
 *
 *   Arguments:
 *     @head:    - Pointer to head of the list.
 *    @line_n:   - Command line number.
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
void pall(stack_t **head, unsigned int line_n)
{
	stack_t *top = NULL;
	(void)line_n;

	top = *head;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
