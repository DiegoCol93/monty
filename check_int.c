#include "monty.h"
/**
 * check_int     - Checks if a string only has numbers.
 *
 *   Arguments:
 *     @data:    - String with data argument.
 *    @line_n:   - Command line.
 *     @head:    - Pointer to head of list.
 *
 *     Return:   - Integer data if no error found.
 *
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
 *                         Dec-2020
 */
int check_int(char *data, unsigned int line_n, stack_t **head)
{
	int ret = 0, i = 0;

	if (data)
	{
		if (data[i] == '-')
			i++;
		while (data[i])
		{
			if (data[i] < '0' || data[i] > '9')
			{
				fprintf(stderr, "L%d: usage: push integer\n",
					line_n);
				free(vars.line);
				fclose(vars.file_stream);
				if (*head || head)
					free_list(head);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		ret = atoi(data);
		return (ret);
	}
	fprintf(stderr, "L%d: usage: push integer\n", line_n);
	exit(EXIT_FAILURE);
}
