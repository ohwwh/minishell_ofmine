/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:17:25 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/15 11:57:04 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*join_and_rm_all(char *s1, char *s2)
{
	char	*s;

	s = NULL;
	s = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
	return (s);
}
