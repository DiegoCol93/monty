#include "monty.h"
/**
 * rotl - Rotates the stack, first element to the back, 2nd to the top.
 *
 *    Arguments:
 *      @head:    - Pointer, received by reference, of head of list.
 *     @line_n:   - Number of line being read.
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
 *                               Dec-2020
 */
void rotl(stack_t **head, unsigned int line_n)
{
	stack_t *last = NULL;

	(void)line_n;
	last = *head;
	if (last)
		if (last->next)
		{
			while (last->next)
				last = last->next;
			*head = (*head)->next;
			(*head)->prev->next = NULL;
			last->next = (*head)->prev;
			last->next->prev = last;
			(*head)->prev = NULL;
		}
}
