#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define _POSIX_C_SOURCE 200809L

/*** GLOBAL VARIABLES ***/
extern char *command[2];

/**
 * struct stack_s - doubly linked list presentation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**** LINKED LISTS FUNCTIONS ****/
stack_t *add_dnodeint(stack_t **head, int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);

/*** INPUT TEXT FUNCTIONS  ***/
FILE *check_input(int argc, char *argv[]);
void (*find_opcode(char *input_code))(stack_t **stack, unsigned int line_number);

/*** OPJECT-CODES FUNCTIONS  ***/
void _push(stack_t **head, unsigned int line_number);

#endif
