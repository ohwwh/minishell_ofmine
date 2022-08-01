/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:12:47 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/15 11:56:53 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_c(char *src, int from, char c)
{
	while (src[from] && src[from] != c)
	{
		from++;
		if (src[from] == '\'' || src[from] == '"')
			ignore_until_c(src, &from, src[from]);
	}
	return (from);
}
