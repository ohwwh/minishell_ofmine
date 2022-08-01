#include "minishell.h"

extern t_global_set	g_set;

static void	ft_clear(char **ret, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{	
		free(ret[i]);
		i ++;
	}
	free(ret);
	exit(ENOMEM);
}

void	init_shell(char **new, int idx)
{
	char	*pwd;
	char	*shell;

	pwd = getcwd(0, 1);
	shell = ft_strjoin("SHELL=", pwd);
	free(pwd);
	pwd = 0;
	if (!shell)
		ft_clear(new, idx);
	new[idx] = shell;
}

void	init_path(char **new, char *envp[], int idx)
{
	while (*(envp[idx]) != '=')
		envp[idx]++;
	envp[idx]++;
	g_set.g_path = ft_strdup(envp[idx]);
	if (!g_set.g_path)
		ft_clear(new, idx);
}

void	init_env(char **envp_new[], char *envp[])
{
	char	**new;
	char	*new_element;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (count_env(envp) + 1));
	while (envp[i])
	{
		if (!ft_strncmp("SHELL", envp[i], 5))
			init_shell(new, i);
		else
		{
			new_element = ft_strdup(envp[i]);
			if (!new_element)
				ft_clear(new, i);
			new[i] = new_element;
			if (!ft_strncmp("PATH", envp[i], 4))
				init_path(new, envp, i);
		}
		i ++;
	}
	new[i] = 0;
	*envp_new = new;
}

void	init_term(char **envp_new[], char *envp[])
{
	struct termios	term;

	g_set.g_path = 0;
	g_set.flag = 0;
	g_set.errno_temp = 0;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	g_set.temp[0] = dup(0);
	g_set.temp[1] = dup(1);
	init_env(envp_new, envp);
}
