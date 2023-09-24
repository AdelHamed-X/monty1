#include "monty.h"

/**
 * tokenizer - parses the text to single tokens
 * @buff: a pointer to the input text
 * @read_bytes: number of read bytes from getline()
 * Return: the token array
 */
char **tokenizer(char *buff, int read_bytes)
{
	char *token, *buff_cp;
	char **token_arr;
	int i = 0, token_count = 0;

	buff_cp = (char *)malloc(sizeof(char) * (read_bytes + 1));
	if (buff_cp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(buff_cp, buff);
	token = strtok(buff_cp, " \t\n");
	while (token)
	{
		token_count++;
		token = strtok(NULL, " ");
	}
	token_count++;

	token_arr = (char **)malloc(token_count * sizeof(char *));
	if (token_arr == NULL)
	{
		free(buff_cp);
		fprintf(stderr, "Error: malloc failed\n");
	}
	token = strtok(buff, " \t\n");
	while (token)
	{
		token_arr[i] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(token_arr[i], token);
		i++;
		token = strtok(NULL, " ");
	}
	token_arr[i] = NULL;

	return (token_arr);
}
