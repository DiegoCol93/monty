#include "monty.h"
/**
 * pstr - Prints the list as ascii characters, until a zero is read,
 *        a non-valid character is read, or the end of the list is
 *        reached.
 *
 *    Arguments:
 *      @head:    - Pointer, received by reference, of head of list.
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
 *                               Dec-2020
 */
void pstr(stack_t **head, unsigned int line_n)
{
	stack_t *top = NULL;

	(void)line_n;
	top = *head;
	if (top)
	{
		while(top)
		{
			if (top->n <= 0 || top->n > 127)
			{
				break;
			}
			putchar(top->n);
			top = top->next;
		}
	}
	putchar(10);
}
