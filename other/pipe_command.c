#include "minishell.h"

extern t_global_set	g_set;

void	front_command(t_node *node, char **envp[], int *fd)
{
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	if (node->left)
		redir(node->left, *envp);
	execute_command(envp, node->right->data);
	shell_exit(errno, *envp);
}

void	back_command(t_node *node, char **envp[], int *fd)
{
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	if (node->left)
		redir(node->left, *envp);
	execute_command(envp, node->right->data);
	shell_exit(errno, *envp);
}

void	single_command_fork(t_node *node, char **envp[])
{
	int	pid;
	int	status;

	pid = fork();
	if (pid)
	{
		waitpid(pid, &status, 0);
		g_set.errno_temp = WEXITSTATUS(status);
	}
	else
	{
		if (node->left)
			redir(node->left, *envp);
		if (node->right)
			execute_command(envp, node->right->data);
		g_set.errno_temp = errno;
		shell_exit(errno, *envp);
	}
}

void	single_command_built(t_node *node, char **envp[])
{
	if (node->left)
		redir(node->left, *envp);
	if (node->right)
		execute_command(envp, node->right->data);
	g_set.errno_temp = errno;
}

void	single_command(t_node *node, char **envp[])
{
	int	built;

	if (!node)
		return ;
	if (node->right)
		built = is_built_in(node->right->data);
	else
		built = 1;
	if (!built)
		single_command_fork(node, envp);
	else
		single_command_built(node, envp);
}
