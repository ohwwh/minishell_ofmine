/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:29:12 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/04 19:02:05 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list *lst, void *item)
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
		lst->front->prev = n;
		n->next = lst->front;
		lst->front = n;
	}
	lst->len++;
}
