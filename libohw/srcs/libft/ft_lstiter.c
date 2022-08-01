/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:32:28 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/04 19:02:23 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list_node	*n;

	if (lst == NULL || f == NULL)
		return ;
	n = lst->front;
	while (n)
	{
		f(n->content);
		n = n->next;
	}
}
