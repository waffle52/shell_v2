#include "hsh.h"

/**
 * hsh_cd - change directory
 * @args: arguments passed to function
 *
 * Return: (1) SUCCESS
 */
int hsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}
