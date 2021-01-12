#include "hsh.h"

char *read_line(void)
{
	char *line = NULL;
	size_t buflen = 0;

	if (getline(&line, &buflen, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(line);
			exit(EXIT_SUCCESS); /* Recieved an EOF */
		}
		else
		{
			perror("readline\n");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}

char **split_line(char *line)
{
	int length = 0;
	int bufsize = TOK_BUFSIZE;
	char **tokens = NULL;
	char *token = NULL;

	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		if (length >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens) {
				fprintf(stderr, "hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOK_DELIM);
	}

	tokens[length] = NULL;
	return (tokens);
}
