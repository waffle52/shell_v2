#ifndef _HSH_H_
#define _HSH_H_

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/**
 * struct data - Struct for bypassing the restriction
 * forbidding global variables
 * @token2: First member
 * @buffer: Second member
 *
 * Description: Allows freeing of certain variables in memory
 * where freeing otherwise would cause errors. This allows for
 * fixing any possible memory leaks
 */

struct data
{
	char *token2;
	char *buffer;
};

void loop(void);
char *read_line(void);
char **split_line(char *line);
int exec(char **args);
int hsh_exit(char **args);
int hsh_cd(char **args);
void atty(void);
int launch(char **args);

#endif
