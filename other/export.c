#include "minishell.h"

extern t_global_set	g_set;

static int	is_valid_export(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '=' | isstring_string(arg) == 0)
	{
		errno = EPERM;
		printf("export: '%s': not a valid identifier\n", arg);
		return (0);
	}
	while (arg[i])
	{
		if (arg[i] == '=')
			break ;
		i ++;
	}
	if (arg[i] == 0)
		return (0);
	return (1);
}

void	env_export_exist(char ***envp, char *new_command, int idx)
{
	if (!ft_strncmp("PATH", new_command, 4))
	{
		free(g_set.g_path);
		g_set.g_path = cut_value(new_command, *envp);
	}
	free((*envp)[idx]);
	(*envp)[idx] = new_command;
}

void	env_export_new(char ***envp, char *new_command)
{
	int		i;
	char	**new;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (count_env(*envp) + 2));
	if (!new)
		shell_exit(ENOMEM, *envp);
	while ((*envp)[i])
	{
		new[i] = (*envp)[i];
		i ++;
	}
	new[i] = new_command;
	new[i + 1] = 0;
	free(*envp);
	*envp = new;
}

int	env_export_string(char ***envp, char *arg)
{
	int		idx;
	char	*new_command;

	if (is_valid_export(arg))
	{
		idx = is_exist(*envp, arg);
		new_command = ft_strdup(arg);
		if (!new_command)
			shell_exit(ENOMEM, *envp);
		if (idx == -1)
			env_export_new(envp, new_command);
		else
			env_export_exist(envp, new_command, idx);
	}
	return (0);
}

int	env_export(char ***envp, char **command)
{
	int		i;

	i = 1;
	while (command[i])
		env_export_string(envp, command[i ++]);
	return (0);
}
