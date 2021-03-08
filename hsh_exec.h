#ifndef _HSH_EXEC_H_
#define _HSH_EXEC_H_

int (*builtin_func[]) (char **) = {
	&hsh_cd,
	&hsh_exit
};

int num_builtins(void);

#endif
