#include "hsh.h"

/**
 * hsh_exit - exit program
 * @args: arguments passed to function
 *
 * Return: (Status)
 */
int hsh_exit(char **args)
{
	int status = 0;
	pid_t pid;

	if (args[1] != NULL)
	{
		if (*(args[1]) <= '9' && *(args[1]) >= '0')
			status = atoi(args[1]);
	}
	pid = fork();
	while (pid != 1)
	{
		_exit(status);
	}

	return (status);
}
