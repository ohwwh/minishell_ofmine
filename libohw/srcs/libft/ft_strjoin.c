/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:09:55 by ohw               #+#    #+#             */
/*   Updated: 2021/11/30 20:28:16 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *s1, char *s2, size_t s1_len)
{
	size_t	idx;

	idx = 0;
	while (s2[idx])
	{
		s1[s1_len + idx] = s2[idx];
		idx++;
	}
	s1[s1_len + idx] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 != NULL)
			return (ft_strdup(s1));
		else if (s2 != NULL)
			return (ft_strdup(s2));
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = 0;
	ft_strcat(res, s1, 0);
	ft_strcat(res, s2, ft_strlen(res));
	return (res);
}