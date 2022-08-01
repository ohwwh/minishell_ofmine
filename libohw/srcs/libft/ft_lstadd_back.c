/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:34:12 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/04 19:01:52 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *lst, void *item)
{
	t_list_node	*n;

	if (lst == NULL || item == NULL)
		return ;
	n = ft_new_node(item);
	if (n == NULL)
		return ;
	if (lst->front == NULL)
	{
		lst->front = n;
		lst->rear = n;
	}
	else
	{
		lst->rear->next = n;
		n->prev = lst->rear;
		lst->rear = n;
	}
	lst->len++;
}
