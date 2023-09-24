#include "monty.h"

char *command[2];

/**
 *
 */
void _push(stack_t **head, unsigned int line_number)
{
	int n = 1;

	if (command[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: invalid integer (command 1 is NULL)\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("atoi\n");
/*	if (isdigit(command[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: invalid integer (isdigit failed)\n", line_number);
                exit(EXIT_FAILURE);
	}

	n = atoi(command[1]);
*/	printf("atoi\n");
	add_dnodeint(head, n);
}
