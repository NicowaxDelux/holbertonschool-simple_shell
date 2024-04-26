#include "header.h"
#define BUFFER_SIZE 1024
/**
  * tokenize_args - tokenize arguments and saved token
  *
  * @buffer: arguments
  *
  * @str: argv[0]
  *
  * @my_tokens: argument tokenize
  */

void tokenize_args(char *buffer, char *str, char **my_tokens)
{
	char *token = NULL, *delimiters = " \t\n";
	int i = 0, j = 0;

	my_tokens = malloc(sizeof(char *) * BUFFER_SIZE);
	if(my_tokens == NULL)
	{
		free(my_tokens);
		exit(1);
	}

	token = strtok(buffer, delimiters);
	for (i = 0; token != NULL; i++)
	{
		my_tokens[i] = token;
		token = strtok(NULL, delimiters);
	}
	my_tokens[i] = NULL;
	for(j = 0; j < i; j++)
	{
		if(*(my_tokens[j]) != '\0')
		{
			execute_command(str, my_tokens[j], my_tokens);
		}
	}
	free(my_tokens);
}
