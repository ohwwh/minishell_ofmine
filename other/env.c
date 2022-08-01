#include "minishell.h"

int	env(char *envp[], char **command)
{
	int	i;

	i = 0;
	if (command[1])
	{
		errno = EPERM;
		return (write(1, "env: too many arguments\n", 24));
	}
	while (envp[i])
		printf("%s\n", envp[i ++]);
	return (0);
}
