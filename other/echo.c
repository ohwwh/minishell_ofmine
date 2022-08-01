#include "minishell.h"

int	nflag(int i, char *arg, int *end)
{
	int			n;
	int			j;

	n = 0;
	if (i == 1 && !(*end) && arg[0] == '-')
	{
		j = 1;
		while (arg[j])
		{
			if (arg[j ++] != 'n')
			{
				*end = 1;
				return (0);
			}
			else
				n ++;
		}
		return (n);
	}
	return (0);
}

int	echo(char **command)
{
	int	i;
	int	n;
	int	isflag;
	int	end;

	i = 1;
	n = 0;
	end = 0;
	while (command[i])
	{
		isflag = nflag(i, command[i], &end);
		n += isflag;
		if (!isflag)
		{
			ft_putstr_fd(command[i], 1);
			if (command[i + 1])
				write(1, " ", 1);
		}
		i ++;
	}
	if (n == 0)
		write(1, "\n", 1);
	return (0);
}
