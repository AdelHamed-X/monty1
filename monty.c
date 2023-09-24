#include "monty.h"

char *command[2] = {NULL, NULL};

/**
 * main - Entry Point
 *
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *head = NULL;
	FILE *file;
	int bytes_read;
	unsigned int line_number = 1;
	size_t buff_size;
	char *buff = NULL;

	file = check_input(argc, argv);

	bytes_read = getline(&buff, &buff_size, file);

	printf("buff is: %s\n", buff);

	while (bytes_read != -1)
	{
		command[0] = strtok(buff, " \t\n");
		printf("command[0] is: %s\n", command[0]);
		if (command[0])
		{
			f = find_opcode(command[0]);

			if (!f)
			{
				fprintf(stderr, "L%u: unknown instruction %s", line_number, command[0]);
				exit(EXIT_FAILURE);
			}
			command[1] = strtok(NULL, " \t\n");
			printf("command[1] is: %s\n", command[1]);
			f(&head, line_number);

			printf("command[1] is: %s\n", command[1]);
		}

		bytes_read = getline(&buff, &buff_size, file);
		line_number++;
	}
	return 0;
}
