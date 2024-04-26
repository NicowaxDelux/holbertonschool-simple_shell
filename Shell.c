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
	int is_terminal = isatty(STDIN_FILENO);

	for (; ;)
	{
		if (is_terminal)
			printf("#cisfun$ ");

		if (getline(&buffer, &size_of_buf, stdin) == EOF)
			break;

		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			return (0);
		}
		if (strcmp(buffer, "env\n") == 0)
		{
			print_environment();
			continue;
		}

		if (*buffer == '\n')
			continue;

		tokenize_args(buffer, argv[0], my_tokens);
	}
	free(buffer);
	return (0);
}
