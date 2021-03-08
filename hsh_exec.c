#include "hsh.h"
#include "hsh_exec.h"

/**
 * exec - execute command
 * @args: arguments passed to function
 * Return: (command to launch) SUCCESS
 */
int exec(char **args)
{
	int i;
	char *builtin_str[] = {
		"cd",
		"exit"
	};

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	return (launch(args));
}

/**
 * num_builtins - get number of builtins
 * Return: Sizeof of builtin_str
 */
int num_builtins(void)
{
	char *builtin_str[] = {
		"cd",
		"exit"
	};
	return (sizeof(builtin_str) / sizeof(char *));
}
