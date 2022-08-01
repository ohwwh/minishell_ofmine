#include "minishell.h"

extern t_global_set	g_set;

static char	*tree_heredoc_dir(char *envp[])
{
	char	*temp;
	char	*ret;

	temp = get_value(envp, "SHELL");
	ret = ft_strjoin(temp, "/heredoc");
	free(temp);
	if (!ret)
		shell_exit(ENOMEM, envp);
	return (ret);
}

static int	tree_heredoc_read(char *end_str, int fd)
{
	char	*pstr;

	pstr = readline("> ");
	if (!pstr || g_set.flag == 3)
	{
		close(fd);
		free(pstr);
		return (2);
	}
	if (!ft_strcmp(pstr, end_str))
	{
		free(pstr);
		return (1);
	}
	write(fd, pstr, ft_strlen(pstr));
	write(fd, "\n", 1);
	free(pstr);
	return (0);
}

void	tree_heredoc(t_list *queue, char *envp[])
{
	char		*pstr;
	char		*dir;
	int			fd;
	int			ret;

	dir = tree_heredoc_dir(envp);
	while (queue->len)
	{
		fd = open(dir, O_RDWR | O_CREAT | O_TRUNC, 0644);
		g_set.flag = 2;
		pstr = dequeue(queue);
		while (1)
		{
			ret = tree_heredoc_read(pstr, fd);
			if (ret == 2)
			{
				free(dir);
				return ;
			}
			else if (ret == 1)
				break ;
		}
		close(fd);
	}
	free(dir);
}
