#include "monty.h"
/**
 * push - Pushes a node into a doubly linked list stack.
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
void push(stack_t **head, unsigned int line_n)
{
	stack_t *new_node = NULL, *top = NULL;
	char *data;
	int n;

	(void)line_n;
	data = strtok(NULL, " ");
	n =  check_int(data, line_n, head);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(vars.line), fclose(vars.file_stream);
		if (*head || head)
			free_list(head);
		exit(1);/* Error if no malloc */
	}
	new_node->n = n, new_node->prev = NULL;
	if (vars.mode == 0) /* Stack mode. */
		if (head)
		{
			if (*head)
			{
				top = *head;
				top->prev = new_node;
			}
			new_node->next = *head;
			*head = new_node;
		}
	if (vars.mode == 1) /* Queue mode. */
		if (head)
			if (*head)
			{
				top = *head;
				while (top->next)
					top = top->next;
				top->next = new_node;
				top->next->prev = top;
			}
			else
				*head = new_node;
}
