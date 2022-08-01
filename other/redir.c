#include "minishell.h"

extern t_global_set	g_set;

void	redir_in(char *file, char *envp[])
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("minishell: %s: %s\n", file, strerror(errno));
		shell_exit(errno, envp);
	}
	dup2(fd, 0);
	close(fd);
}

void	redir_in_heredoc(char *envp[])
{
	char		*pstr;
	char		*temp;
	int			fd;

	pstr = get_value(envp, "SHELL");
	temp = ft_strjoin(pstr, "/heredoc");
	free(pstr);
	fd = open(temp, O_RDONLY);
	free(temp);
	dup2(fd, 0);
	close(fd);
}

void	redir_out(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, 1);
	close(fd);
}

void	redir_out_double(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_APPEND);
	dup2(fd, 1);
	close(fd);
}

void	redir(t_node *node, char *envp[])
{
	if (node->left && node->left->type == REDIR)
		redir(node->left, envp);
	if (node->right && node->right->type == REDIR)
		redir(node->right, envp);
	if (!node->left && !node->right)
	{
		if (node->data[0][0] == '>')
		{
			if (node->data[0][1] == '>')
				redir_out_double(node->data[1]);
			else if (!node->data[0][1])
				redir_out(node->data[1]);
		}
		else if (node->data[0][0] == '<')
		{
			if (node->data[0][1] == '<')
				redir_in_heredoc(envp);
			else if (!node->data[0][1])
				redir_in(node->data[1], envp);
		}
	}
}
