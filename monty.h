#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                               Structures.                                 */
/*---------------------------------------------------------------------------*/

/* - - - - - - - Strcuct 1.                                                  */
/**
 * struct stack_s - Doubly linked list representation
 *                  of a stack (or queue).
 *    Elements:
 *       @n:      - Integer.
 *      @prev:    - Points to the previous element of the stack (or queue).
 *      @next:    - Points to the next element of the stack (or queue).
 *
 *   Description: - Doubly linked list node structure for stack, queues,
 *                  LIFO, FIFO Holberton project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* - - - - - - - Strcuct 2.                                                  */
/**
 * struct instruction_s - Opcode and its function.
 *
 *      Elements:
 *       @opcode:       - The opcode.
 *          @f:         - Function to handle the opcode.
 *
 *     Description:     - Opcode and its function
 *                        for stack, queues,
 *                        LIFO, FIFO Holberton project.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                         Stack handling functions.                         */
/*---------------------------------------------------------------------------*/

/*   push - Pushes a node into memory                                        */
void push(stack_t **head, unsigned int line_n);

/*   pall - Prints the list.                                                 */
void pall(stack_t **head, unsigned int line_n);

/*   pint - Prints the top of the stack.                                     */
void pint(stack_t **head, unsigned int line_n);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                         Main auxiliary functions.                         */
/*---------------------------------------------------------------------------*/

/*   get_monty_code - Gets the correct function for the opcode.              */
void get_monty_code(stack_t **head, char *opcode, unsigned int line_n);

/*    remove_new_line - Removes the newline from a string.                   */
char *remove_new_line(char *line);

/*  check_int - Checks if a string only has numbers.                         */
int check_int(char *data, unsigned int line_n);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /*_MONTY_H_*/
