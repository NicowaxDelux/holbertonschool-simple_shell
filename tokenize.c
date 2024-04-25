#include "header.h"

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
	char *token = NULL;
	int i = 0, status;
	pid_t pid;
	my_tokens = NULL;

	my_tokens = malloc(sizeof(char *) * 1024);

	token = strtok(buffer, " \n");
	for (i = 0; token != NULL; i++)
	{
		my_tokens[i] = token;
		token = strtok(NULL, " ");
	}
	my_tokens[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(41);
	}
	if (pid == 0)
		execute_command(str, my_tokens);
	else
		wait(&status);
}
