#include "monty.h"
/**
 * divis - Divides the top two elements on top of the stack.
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
void divis(stack_t **head, unsigned int line_n)
{
	stack_t *top = NULL;

	top = *head;
	if (!top || !top->next)
	{
		fprintf(stderr,
			"L%d: can't div, stack too short\n",
			line_n);
		free(vars.line);
		fclose(vars.file_stream);
		if (*head || head)
			free_list(head);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr,
			"L%d: division by zero\n",
			line_n);
		free(vars.line);
		fclose(vars.file_stream);
		if (*head || head)
			free_list(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		top->next->n = top->next->n / top->n;
		*head = top->next;
		free(top);
	}
}
