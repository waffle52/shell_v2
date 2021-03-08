#include "hsh.h"

/**
 * main - entry point
 * @argc: number of args passed
 * @argv: arguments passed
 * @env_cmd: evironment command
 * Return: (EXIT_SUCCESS) SUCCESS
 */

int main(int argc, char *argv[], char **env_cmd)
{
	(void)argc, (void)argv, (void)env_cmd;

	signal(SIGINT, SIG_IGN);
	/* env_string = _getenv("PATH", env_cmd);*/
	/*atty();*/
	loop();

	return (EXIT_SUCCESS);
}

/**
 * loop - loop prompt
 */
void loop(void)
{
	char *line = NULL;
	char **tokens = NULL;
	int status = 1;

	do {
		printf("hsh: ");
		line = read_line();

		tokens = split_line(line);

		status = exec(tokens);
		free(tokens);
		free(line);
	} while (status == 1);
}

/**
 * launch - launch prompt
 * @args: args passed to call
 * Return: (1) SUCCESS
 */
int launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("hsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("hsh");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	(void)wpid;
	return (1);
}

/**
 * atty - check for itneractive
 */
void atty(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
}
