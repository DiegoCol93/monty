#include "monty.h"
/**
 * pint          - Prints the value at the top of the stack/list.
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
void pint(stack_t **head, unsigned int line_n)
{
	stack_t *top = NULL;

	top = *head;
	if (!top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			line_n);
		free(vars.line);
		fclose(vars.file_stream);
		if (*head || head)
			free_list(head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
