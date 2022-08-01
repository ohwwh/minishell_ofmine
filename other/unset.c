#include "minishell.h"

extern t_global_set	g_set;

static void	ft_free(char ***envp, char *arg, char **new)
{
	free(*envp);
	*envp = new;
	if (!ft_strncmp("PATH", arg, 4))
	{
		free(g_set.g_path);
		g_set.g_path = 0;
	}
}

static int	is_valid_unset(char *arg)
{
	int	i;

	i = 0;
	if (ft_strchr(arg, '=') != 0 | isstring_string(arg) == 0)
	{
		errno = EPERM;
		printf("unset: '%s': not a valid identifier\n", arg);
		return (0);
	}
	while (arg[i])
	{
		if (arg[i] == '=')
			break ;
		i ++;
	}
	return (1);
}

void	unset_string(char ***envp, char *arg)
{
	int		j;
	int		k;
	int		idx;
	char	**new;

	idx = is_exist(*envp, arg);
	if (!is_valid_unset(arg) || idx == -1)
		return ;
	j = 0;
	k = 0;
	new = (char **)malloc(sizeof(char *) * count_env(*envp));
	if (!new)
		shell_exit(ENOMEM, *envp);
	while ((*envp)[k])
	{
		if (idx != j)
			new[j ++] = (*envp)[k ++];
		else
		{
			free((*envp)[k ++]);
			idx --;
		}
	}
	new[j] = 0;
	ft_free(envp, arg, new);
}

void	unset(char ***envp, char **command)
{
	int	i;

	i = 1;
	while (command[i])
		unset_string(envp, command[i ++]);
}
