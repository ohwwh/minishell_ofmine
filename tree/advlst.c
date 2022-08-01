/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:22:40 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/15 11:56:38 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**lst_to_arr(t_list *l)
{
	char		**res;
	t_list_node	*n;
	int			i;

	if (l->len == 0)
		return (NULL);
	res = (char **)malloc((l->len + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[l->len] = NULL;
	n = l->front;
	i = 0;
	while (n)
	{
		res[i++] = (char *)n->content;
		n = n->next;
	}
	return (res);
}
