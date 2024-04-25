#include "header.h"

/**
  * main - simple shell
  *
  * @argc: argument counts
  *
  * @argv: varguments vector
  *
  * Return: return 0
  */

int main(int argc __attribute__((unused)), char **argv)
{
	char *buffer = NULL, **my_tokens = NULL;
	size_t size_of_buf = 40;
	pid_t pid;

	buffer = (char *)malloc(size_of_buf * sizeof(char));

	if (buffer == NULL)
	{
		free(buffer);
		exit(1);
	}
	for (; ;)
	{
		printf("#cisfun$ ");

		if (getline(&buffer, &size_of_buf, stdin) == EOF)
			break;

		if (*buffer == '\n')
			continue;

		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
			tokenize_args(buffer, argv[0], my_tokens);
		else
			wait(NULL);
	}
	return (0);
}
