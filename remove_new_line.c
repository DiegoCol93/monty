#include "monty.h"
/**
 * remove_new_line - Removes newline character from the read line.
 *
 *    Arguments:
 *      @line:      - Pointer to the string of the current line.
 *
 *      Return:     - String without the new_line.
 *             _____   __  ______  ______  ______
 *            /\  __-./\ \/\  ___\/\  ___\/\  __ \
 *            \ \ \/\ \ \ \ \  __\\ \ \__ \ \ \/\ \
 *             \ \____-\ \_\ \_____\ \_____\ \_____\
 *              \/____/ \/_/\/_____/\/_____/\/_____/
 *              __      ______  ______  ______  ______
 *             /\ \    /\  __ \/\  == \/\  ___\/\___  \
 *             \ \ \___\ \ \/\ \ \  _-/\ \  __\\/_/  /__
 *              \ \_____\ \_____\ \_\   \ \_____\/\_____\
 *               \/_____/\/_____/\/_/    \/_____/\/_____/
 *
 *                             Dec-2020
 *
 */
char *remove_new_line(char *line)
{
	unsigned int i;

	if (line)
		for (i = 0; line[i]; i++)
			if (line[i] == '\n')
				line[i] = '\0';
	return (line);
}
