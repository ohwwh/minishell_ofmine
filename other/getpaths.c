#include "minishell.h"

static int	wordcount(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt ++;
			while (*s && *s != c)
				s ++;
		}
		else
			s ++;
	}
	return (cnt);
}

static int	wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i ++;
	return (i);
}

static char	*ft_dup(const char *src, char c, char *command, size_t command_len)
{
	int		i;
	int		j;
	char	*ret;

	ret = (char *)malloc((wordlen(src, c) + command_len + 2) * sizeof(char));
	if (ret)
	{
		i = 0;
		while (src[i] && src[i] != c)
		{
			ret[i] = src[i];
			i ++;
		}
		ret[i ++] = '/';
		j = 0;
		while (command[j])
		{
			ret[i ++] = command[j];
			j ++;
		}
		ret[i] = 0;
	}
	return (ret);
}

static void	ft_clear(char **ret, int index, char *envp[])
{
	int		i;

	i = 0;
	while (i < index)
	{	
		free(ret[i]);
		i ++;
	}
	free(ret);
	shell_exit(ENOMEM, envp);
}

char	**get_paths(char const *s, char c, char *command, char *envp[])
{
	char		**ret;
	int			i;
	const int	command_len = ft_strlen(command);

	if (!s)
		return (0);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!ret)
		shell_exit(ENOMEM, envp);
	while (*s)
	{
		if (*s != c && *s)
		{
			ret[i] = ft_dup(s, c, command, command_len);
			if (!ret[i])
				ft_clear(ret, i, envp);
			i ++;
			s += wordlen(s, c);
		}
		else
			s ++;
	}
	ret[i] = 0;
	return (ret);
}
