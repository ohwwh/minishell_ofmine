/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:08:06 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/17 11:39:20 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_meta	*new_meta(char *s, int f, int t)
{
	t_meta	*m;

	m = (t_meta *)malloc(sizeof(t_meta));
	if (m == NULL)
		return (NULL);
	m->from = f;
	m->src = s;
	m->to = t;
	return (m);
}

t_node	*new_node(t_node_type nt, char **data)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	n->data = data;
	n->type = nt;
	n->left = NULL;
	n->right = NULL;
	return (n);
}

t_tree	*new_tree(void)
{
	t_tree	*t;

	t = (t_tree *)malloc(sizeof(t_tree));
	if (t == NULL)
		return (t);
	t->root = new_node(PIPE, NULL);
	t->queue = ft_lstnew();
	return (t);
}
