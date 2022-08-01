/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:24:58 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/01 11:17:00 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_node	*ft_new_node(void *item)
{
	t_list_node	*n;

	n = (t_list_node *)malloc(sizeof(t_list_node));
	if (n == NULL)
		return (NULL);
	n->content = item;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}

t_list	*ft_lstnew(void)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (l == NULL)
		return (NULL);
	l->front = NULL;
	l->rear = NULL;
	l->len = 0;
	return (l);
}
