/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:58:40 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/17 15:18:29 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*dequeue(t_list *l)
{
	t_list_node	*n;
	char		*ret;

	if (l == NULL || l->len == 0)
		return (NULL);
	n = l->front;
	ret = n->content;
	free(n);
	if (l->len == 1)
	{
		l->front = NULL;
		l->rear = NULL;
	}
	else
		l->front = n->next;
	l->len--;
	return (ret);
}

void	enqueue(t_list *l, char *src)
{
	if (src == NULL)
		return ;
	ft_lstadd_back(l, (void *)src);
}
