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
 *     Members:
 *        @n:     - Integer.
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
 *       Members:
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
/*                        Memory handling functions.                         */
/*---------------------------------------------------------------------------*/

/*   push - Pushes a node into memory                                        */
void push(stack_t **head, unsigned int line_n);

/*   pall - Prints the list.                                                 */
void pall(stack_t **head, unsigned int line_n);

/*   pint - Prints the top of the stack.                                     */
void pint(stack_t **head, unsigned int line_n);

/*   pop_h - Pops the top element of the stack.                              */
void pop_h(stack_t **head, unsigned int line_n);

/*   swap - Swaps the top two elements on the stack.                         */
void swap(stack_t **head, unsigned int line_n);

/*   _nope - Does not do anything.                                           */
void _nope(stack_t **head, unsigned int line_n);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                              Math functions.                              */
/*---------------------------------------------------------------------------*/

/*   added - Adds the top two elements on the stack.                         */
void added(stack_t **head, unsigned int line_n);

/*   _subs - Substracts the top two elements on the stack.                   */
void _subs(stack_t **head, unsigned int line_n);

/*   divis - Divides the top two elements on the stack.                      */
void divis(stack_t **head, unsigned int line_n);

/*   multi - Multiplies the top two elements on the stack.                   */
void multi(stack_t **head, unsigned int line_n);

/*   modul - Modulus operation of the top two elements on the stack.         */
void modul(stack_t **head, unsigned int line_n);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                          Text handling functions.                         */
/*---------------------------------------------------------------------------*/

/*   pchar - Prints value on the top of the stack as one char in ascci.      */
void pch(stack_t **head, unsigned int line_n);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                         Main auxiliary functions.                         */
/*---------------------------------------------------------------------------*/

/*   get_monty_code - Gets the correct function for the opcode.              */
void get_monty_code(stack_t **head, char *opcode, unsigned int line_n);

/*    remove_new_line - Removes the newline from a string.                   */
char *remove_new_line(char *line);

/*  check_int - Checks if a string only has numbers.                         */
int check_int(char *data, unsigned int line_n, stack_t **head);

/*   free_list - Frees the whole list.                                       */
void free_list(stack_t **head);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                        Global variables structure.                        */
/*---------------------------------------------------------------------------*/
/* - - - - - - - Strcuct 0.                                                  */
/**
 * struct vars_s   - Global structure for passing variables,
 *                   specially for error handling purposes.
 *
 *     Members:
 *  @file_stream:  - Pointer to the file stream.
 *      @line:     - Pointer to the current line.
 *
 *   Descriptions: - Structure for storing variables used
 *                   when closing on error.
 */
typedef struct vars_s
{
	FILE *file_stream;
	char *line;
} vars_t;
extern vars_t vars;
vars_t vars;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /*_MONTY_H_*/
