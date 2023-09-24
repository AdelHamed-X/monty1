#include "monty.h"

/**
 *
 */
void (*find_opcode(char *input_code))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode[] = {
		{"push", _push},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcode[i].f != NULL; i++)
	{
		if (strcmp(opcode[i].opcode, input_code) == 0)
			break;
	}
	return (opcode[i].f);
}
