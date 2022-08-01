#include "minishell.h"

t_global_set	g_set;

int	is_built_in(char **command)
{
	int	ret;

	ret = 0;
	if (!ft_strcmp(command[0], "cd"))
		ret = 1;
	else if (!ft_strcmp(command[0], "echo"))
		ret = 1;
	else if (!ft_strcmp(command[0], "env"))
		ret = 1;
	else if (!ft_strcmp(command[0], "exit"))
		ret = 1;
	else if (!ft_strcmp(command[0], "export"))
		ret = 1;
	else if (!ft_strcmp(command[0], "pwd"))
		ret = 1;
	else if (!ft_strcmp(command[0], "unset"))
		ret = 1;
	else if (!ft_strcmp(command[0], "getpid"))
		ret = 1;
	return (ret);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i ++]);
	free(arr);
}

void	check_args(int argc, char *argv[])
{
	if (argc != 1 || argv == NULL)
		exit(EPERM);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*pstr;
	t_tree	*tree;
	char	**envp_new;

	check_args(argc, argv);
	init_term(&envp_new, envp);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	while (1)
	{
		g_set.flag = 0;
		dup2(g_set.temp[0], 0);
		dup2(g_set.temp[1], 1);
		pstr = readline("minishell-3.0$ ");
		g_set.flag = 1;
		if (!pstr)
			pstr = "exit";
		tree = parse(ft_strdup(pstr), envp_new);
		add_history(pstr);
		if (tree)
			execute_tree(tree, &envp_new);
		free(pstr);
		destroy_tree(tree);
	}
}
