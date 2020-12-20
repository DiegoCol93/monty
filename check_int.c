#include "monty.h"
/**
 * check_int     - Pushes a node into a doubly linked list stack.
 *
 *   Arguments:
 *     @data:    - String with data argument.
 *    @line_n:   - Command line.
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
int check_int(char *data, unsigned int line_n)
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
				fprintf(stderr,
					"\033[31mL%d: usage: push integer\033[0m\n",
					line_n);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		ret = atoi(data);
		return (ret);
	}
	fprintf(stderr, "\033[31mL%d: usage: push integer\033[0m\n", line_n);
	exit(EXIT_FAILURE);
}
