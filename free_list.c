#include "monty.h"
/**
 * free_list - Frees a doubly linked list.
 *
 *  Argument:
 *   @head:  - Pointer to head of the list.
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
void free_list(stack_t **head)
{
	if (head)
	{
		while ((*head)->next)
		{
			*head = (*head)->next;
			free((*head)->prev);
		}
		free(*head);
	}
}