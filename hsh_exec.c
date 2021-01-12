#include "hsh.h"
#include "hsh_exec.h"

int exec(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for(i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (*builtin_func[i])(args);
		}
	}

	return launch(args);
}

int num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}
