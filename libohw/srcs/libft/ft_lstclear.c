/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:15:30 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/04 19:02:15 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *lst, void (*del)(void *))
{
	t_list_node	*n;
	t_list_node	*target;

	if (lst == NULL || del == NULL)
		return ;
	n = lst->front;
	while (n)
	{
		target = n;
		n = n->next;
		del(target->content);
		free(target);
		target = NULL;
	}
	free(lst);
	lst = NULL;
}
