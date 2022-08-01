#include "minishell.h"

int	count_env(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i ++])
	{
	}
	return (i);
}

int	is_exist(char *envp[], char *key)
{
	int	ret;
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		ret = 1;
		while (envp[i][j] && envp[i][j] != '=')
		{
			if (key[j] != envp[i][j])
			{
				ret = -1;
				break ;
			}
			j ++;
		}
		if (ret != -1)
			return (i);
		i ++;
	}
	return (ret);
}

char	*cat_env(char *key, char *val, char *envp[])
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(key) + ft_strlen(val) + 2));
	if (!ret)
		shell_exit(ENOMEM, envp);
	i = 0;
	j = 0;
	while (key[j])
	{
		ret[i] = key[j];
		i ++;
		j ++;
	}
	ret[i ++] = '=';
	j = 0;
	while (val[j])
	{
		ret[i] = val[j];
		i ++;
		j ++;
	}
	ret[i] = 0;
	return (ret);
}

char	*cut_value(char *str, char *envp[])
{
	char	*ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (str[j])
	{
		if (str[j] == '=')
			k = j;
		j ++;
	}
	ret = (char *)malloc(sizeof(char) * (j - k));
	if (!ret)
		shell_exit(ENOMEM, envp);
	k ++;
	j = 0;
	while (str[k])
	{
		ret[j] = str[k];
		j ++;
		k ++;
	}
	ret[j] = 0;
	return (ret);
}

char	*get_value(char *envp[], char *key)
{
	char	*ret;
	int		flag;
	int		i;
	int		j;

	i = 0;
	ret = 0;
	while (envp[i])
	{
		j = 0;
		flag = 1;
		while (envp[i][j] && envp[i][j] != '=')
		{
			if (key[j] != envp[i][j])
			{
				flag = -1;
				break ;
			}
			j ++;
		}
		if (flag != -1)
			return (cut_value(envp[i], envp));
		i ++;
	}
	return (ret);
}
