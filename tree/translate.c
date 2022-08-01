/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:01:45 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/24 20:29:24 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global_set	g_set;

static
char	*get_errno(void)
{
	return (ft_itoa(g_set.errno_temp));
}

static
char	*ts_env(char *s, int *i, char *envp[])
{
	char	*key;
	char	*val;
	int		s_i;

	key = NULL;
	s_i = ++(*i);
	if (s[s_i] == '?')
	{
		(*i)++;
		return (get_errno());
	}
	while (s[*i] && ft_isalnum(s[*i]))
		(*i)++;
	if (s_i == *i)
		return (ft_strdup("$"));
	key = ft_substr(s, s_i, *i - s_i);
	if (key == NULL)
		return (NULL);
	val = get_value(envp, key);
	free(key);
	if (val == NULL)
		return (NULL);
	return (val);
}

static
char	*ts_home(int *i, char *envp[])
{
	(*i)++;
	return (ft_strdup(get_value(envp, "HOME")));
}

static
char	*_substr(char *s, int *i)
{
	int	s_i;

	s_i = *i;
	while (s[*i] && s[*i] != '$')
		(*i)++;
	return (ft_substr(s, s_i, *i - s_i));
}

char	*translate(char *s, char *envp[])
{
	char	*tmp;
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '$')
			tmp = ts_env(s, &i, envp);
		else if (s[i] == '~')
			tmp = ts_home(&i, envp);
		else
			tmp = _substr(s, &i);
		res = join_and_rm_all(res, tmp);
	}
	free(s);
	s = NULL;
	return (res);
}
