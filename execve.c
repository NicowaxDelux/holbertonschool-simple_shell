#include "header.h"

/**
  * execute_command - excute a argument
  *
  * @str: argv[0]
  *
  * @my_tokens: tokens
  */

void execute_command(char *str, char *command, char *my_tokens[])
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(41);
	}
	if (pid == 0)
	{
		if ((execve(command, my_tokens, NULL)) == -1)
		{
			fprintf(stderr, "%s: %s\n", str, strerror(errno));
			exit(175);
		}
	}
	else
		wait(NULL);
}
